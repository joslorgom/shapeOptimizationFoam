    // Adjoint Momentum predictor

    //volVectorField adjointTransposeConvection((fvc::grad(V) & U));
    //volVectorField adjointTransposeConvection
    //(
    //    fvc::reconstruct
    //    (
    //        mesh.magSf()*fvc::dotInterpolate(fvc::snGrad(Ua), U)
    //    )
    //);

    volVectorField adjointTransposeConvection((- fvc::grad(U) & V));

    tmp<fvVectorMatrix> tVEqn
    (
        fvm::div(-phi, V)
      - adjointTransposeConvection
      + turbulence->divDevReff(V)
     ==
        fvOptions(V)
    );
    fvVectorMatrix& VEqn = tVEqn.ref();

    VEqn.relax();

    fvOptions.constrain(VEqn);

    solve(VEqn == -fvc::grad(q));

    fvOptions.correct(V);
