
	//autoPtr<motionSolver> motionPtr = motionSolver::New(mesh);

	pointVectorField& PointDisplacement = const_cast<pointVectorField&>
	(
	    mesh.objectRegistry::lookupObject<pointVectorField>
	    (
		"pointDisplacement"
	    )
	);

	//PointDisplacement.boundaryFieldRef()[patchI] == displacements;


	//Info << "Point displacement size is " << PointDisplacement.boundaryFieldRef()[patchID].size() << nl << endl;
	//Get the vector field of the patch
	vectorField &pDisp = refCast<vectorField>(PointDisplacement.boundaryFieldRef()[patchID]);

	//Find the relevant size of the vector and declare a vectorField.
	int Psize= pDisp.size();
	vectorField dispVals(Psize);

	// displacement based on the external calculation
	scalarField sensitivityPatch = surfSens.boundaryField()[patchID]/gMax(mag(surfSens.boundaryField()[patchID]));

	//- set-up interpolator
	primitivePatchInterpolation patchInterpolator( mesh.boundaryMesh()[patchID] );

	//- perform interpolation
	scalarField faceValues = patchInterpolator.faceToPointInterpolate(sensitivityPatch);

	vectorField &PointPointer = refCast<vectorField>(PointDisplacement.boundaryFieldRef()[patchID]);
	vectorField PointNormalVector = mesh.boundaryMesh()[patchID].pointNormals();

	// loop over points to move the nodes
	forAll(dispVals, index)
	{
	    dispVals[index].x() = PointPointer[index].x() - gamma * faceValues[index] * PointNormalVector[index].x();
            dispVals[index].y() = PointPointer[index].y() - gamma * faceValues[index] * PointNormalVector[index].y();
            dispVals[index].z() = PointPointer[index].z() - gamma * faceValues[index] * PointNormalVector[index].z();
	}

	PointDisplacement.boundaryFieldRef()[patchID] == dispVals;

	mesh.update();
