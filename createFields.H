/****************************************************************/
// Primal fields
/****************************************************************/

Info<< "Reading primal field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading primal field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, simple.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());

/****************************************************************/

/****************************************************************/
// Adjoint fields
/****************************************************************/

Info<< "Reading adjoint field q\n" << endl;
volScalarField q
(
    IOobject
    (
        "q",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading adjoint field V\n" << endl;
volVectorField V
(
    IOobject
    (
        "V",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPsi.H"

label qRefCell = 0;
scalar qRefValue = 0.0;
setRefCell(q, simple.dict(), qRefCell, qRefValue);
mesh.setFluxRequired(q.name());

/****************************************************************/

/****************************************************************/
// Turbulence model
/****************************************************************/

singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

/****************************************************************/

Info << "Reading transportProperties\n" << endl;
IOdictionary transportProperties
(
    IOobject
    (
	"transportProperties",
	runTime.constant(),
	mesh,
	IOobject::MUST_READ,
	IOobject::NO_WRITE
    )
);

dimensionedScalar nu(transportProperties.lookup("nu"));
dimensionedScalar rho(transportProperties.lookup("rho"));

Info << "Reading numericalParameters\n" << endl;
IOdictionary numericalParameters
(
    IOobject
    (
	"numericalParameters",
	runTime.constant(),
	mesh,
	IOobject::MUST_READ,
	IOobject::NO_WRITE
    )
);

wordList movingPatches(numericalParameters.lookup("movingPatches"));
scalar gamma(readScalar(numericalParameters.lookup("gamma")));
scalar wDrag(readScalar(numericalParameters.lookup("wDrag")));
scalar wLift(readScalar(numericalParameters.lookup("wLift")));

// Drag and Lift directions
vector dragDir(numericalParameters.lookup("dragDir"));
dragDir = dragDir / mag(dragDir);
vector liftDir(numericalParameters.lookup("liftDir"));
liftDir = liftDir / mag(liftDir);

/****************************************************************/
// Surface sensitivities
/****************************************************************/

surfaceScalarField surfSens
(
    IOobject
    (
	"surfSens",
	runTime.timeName(),
	mesh,
	IOobject::READ_IF_PRESENT,
	IOobject::AUTO_WRITE
    ),
    (- nu * (mesh.Sf() & fvc::interpolate( twoSymm(fvc::grad(V)) ) / mesh.magSf()) ) & fvc::snGrad(U)
);

/****************************************************************/

scalarField volField = mesh.V();
