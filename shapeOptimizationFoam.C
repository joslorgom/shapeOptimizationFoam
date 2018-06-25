/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    shapeOptimizationFoam

Description
    Shape optimization solver for steady-state, incompressible, turbulent flow, 
    using the SIMPLE algorithm.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "singlePhaseTransportModel.H"
#include "turbulentTransportModel.H"
#include "simpleControl.H"
#include "fvOptions.H"

#include "dynamicFvMesh.H"
#include "primitivePatchInterpolation.H"
#include "fixedValuePointPatchField.H"

/****************************************************************/
// Libraries for mesh motion
/****************************************************************/
/*
#include "meshTools.H"
#include "primitiveMesh.H"
#include "primitivePatch.H"
#include "dynamicFvMesh.H"
#include "primitivePatchInterpolation.H"
#include "pointMesh.H" //Perhaps not needed..?
#include "pointFields.H" //Perhaps not needed..?
#include "pointPatchField.H"
#include "volPointInterpolation.H"
#include "fixedValuePointPatchField.H"

// Common in moveMesh.C, myMoveMesh.C and sensitivityMoveMesh.C
#include "argList.H"
#include "Time.H"
#include "fvMesh.H"
#include "motionSolver.H"

//#include "fvIOoptionList.H"
#include "velocityMotionSolver.H"

#include "fvcSmooth.H"
#include "bound.H"
*/
/****************************************************************/

/****************************************************************/
// Dynamic Mesh
/****************************************************************/
//#include "dynamicFvMesh.H"
//#include "CorrectPhi.H"
/****************************************************************/

/****************************************************************/

int main(int argc, char *argv[])
{
    #include "postProcess.H"

    #include "setRootCase.H"
    #include "createTime.H"
    #include "createDynamicFvMesh.H"
    #include "createControl.H"
    #include "createFields.H"
    #include "createFvOptions.H"
    #include "initContinuityErrs.H"

    #include "initAdjointContinuityErrs.H"

    /****************************************************************/
    // Dynamic Mesh
    /****************************************************************/
    //#include "createDynamicFvMesh.H"
    //#include "createUf.H"
    //#include "CourantNo.H"
    /****************************************************************/

    // Disable solver output
    lduMatrix::debug = 0;
    solverPerformance::debug = 0;

    turbulence->validate();

    /****************************************************************/

    scalar volSum = gSum(volField);

    scalar Ja = VGREAT;
    scalar J = VGREAT;
    scalar dJ = wDrag*wLift;
    label count = 0;
    label j = 1;

    std::ofstream file("results.csv");

    Info << "\nStarting loop\n" << endl;

    while (simple.loop())
    {
	Info << "Iteration no. " << runTime.timeName() << nl << endl;

	/****************************************************************/
	// Primal equations
	/****************************************************************/

	Info << "Solving primal system..." << endl;
        // Pressure-velocity SIMPLE corrector
	for (j = 1; j <= 10; j++)
        {
            #include "UEqn.H"
            #include "pEqn.H"
        }

	/****************************************************************/

	Info << nl << endl;
	#include "adjointBC.H"

	/****************************************************************/
	// Adjoint equations
	/****************************************************************/

	Info << "Solving adjoint system..." << endl;
        // Adjoint pressure-velocity SIMPLE corrector
	for (j = 1; j<=10; j++)
        {
            #include "VEqn.H"
            #include "qEqn.H"
        }

	/****************************************************************/

        laminarTransport.correct();
        turbulence->correct();

	#include "dragAndLift.H"

	volField = mesh.V();
	volSum = gSum(volField);

      	file << runTime.value() << "," << J << "," << drag.value() << "," << lift.value() << "," << volSum << nl;

	//surfSens = fvc::interpolate ( ( fvc::grad(p) - nu * fvc::div( twoSymm (fvc::grad(U)) ) )  & ( wDrag*dragDir + wLift*liftDir ) );
	surfSens = ( ( - nu * ( fvc::interpolate( twoSymm(fvc::grad(V)) ) & ( mesh.Sf() ) / mesh.magSf() ) ) & fvc::snGrad(U) );

	scalar thetaSum(0);
	scalar areaSum(0);

	forAll(cPatch,faceI) 
	{
		thetaSum = thetaSum + surfSens.boundaryField()[patchID][faceI] * mesh.magSf().boundaryField()[patchID][faceI];
		areaSum = areaSum + mesh.magSf().boundaryField()[patchID][faceI];
	}

	surfSens = surfSens - dimensionedScalar("r", surfSens.dimensions(), ( thetaSum / areaSum ) );

	#include "updateMesh.H"

	volField = mesh.V();
	Info << "Domain volume is " << gSum(volField) << endl;

        runTime.write();
/*
        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
*/
    }

    file.close();

    Info<< "End\n" << endl;

    return 0;
}
