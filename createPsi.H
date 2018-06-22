/****************************************************************/
// Creates and initialises the adjoint face-flux field psi
/****************************************************************/

Info<< "Reading/calculating adjoint face flux field psi\n" << endl;

surfaceScalarField psi
(
    IOobject
    (
        "psi",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    linearInterpolate(V) & mesh.Sf()
);

/****************************************************************/
