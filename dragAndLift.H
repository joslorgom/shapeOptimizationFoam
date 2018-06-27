word patchName = "walls";
label patchID = mesh.boundaryMesh().findPatchID(patchName);

const polyPatch& cPatch = mesh.boundaryMesh()[patchID];

surfaceScalarField pSurf( fvc::interpolate(p) );
//surfaceVectorField vSurf( fvc::interpolate( twoSymm(fvc::grad(U)) ) & mesh.Sf() );

surfaceVectorField vSurf( fvc::interpolate( turbulence->devReff() ) & mesh.Sf() );

vector fSum(0, 0, 0);

forAll(cPatch,faceI)
{
	fSum = fSum + pSurf.boundaryField()[patchID][faceI] * mesh.Sf().boundaryField()[patchID][faceI];
	//fSum = fSum - nu.value() * vSurf.boundaryField()[patchID][faceI];
	fSum = fSum + vSurf.boundaryField()[patchID][faceI];
}

fSum = fSum * rho.value();

dimensionedScalar drag(dragDir & fSum);
dimensionedScalar lift(liftDir & fSum);

Ja = J;
J = wDrag*drag.value() - wLift*lift.value();
dJ = J - Ja;

if(dJ > 0)
    {count ++;}
else
    {count = 0;}

Info << "Drag direction: " << dragDir << " - Drag: " << drag.value() << endl;
Info << "Lift direction: " << liftDir << " - Lift: " << lift.value() << endl;
