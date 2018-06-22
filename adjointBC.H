forAll(movingPatches,i)
{
    const word& patchName = movingPatches[i];
    label patchID = mesh.boundaryMesh().findPatchID(patchName);

    V.boundaryFieldRef()[patchID] == - (wDrag*dragDir - wLift*liftDir);
    V.correctBoundaryConditions();
} 
