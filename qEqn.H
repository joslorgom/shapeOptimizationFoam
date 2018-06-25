{
    volScalarField rAV(1.0/VEqn.A());
    volVectorField HbyAa(constrainHbyA(rAV*VEqn.H(), V, q));
    surfaceScalarField psiHbyAa("psiHbyAa", fvc::flux(HbyAa));
    adjustPhi(psiHbyAa, V, q);

    tmp<volScalarField> rAtV(rAV);

    if (simple.consistent())
    {
        rAtV = 1.0/(1.0/rAV - VEqn.H1());
        psiHbyAa +=
            fvc::interpolate(rAtV() - rAV)*fvc::snGrad(q)*mesh.magSf();
        HbyAa -= (rAV - rAtV())*fvc::grad(q);
    }

    tVEqn.clear();

    // Update the pressure BCs to ensure flux consistency
    constrainPressure(q, V, psiHbyAa, rAtV());

/*
    // Non-orthogonal pressure corrector loop
    while (simple.correctNonOrthogonal())
    {
        fvScalarMatrix qEqn
        (
            fvm::laplacian(rAtV(), q) == fvc::div(psiHbyAa)
        );

        qEqn.setReference(qRefCell, qRefValue);

        qEqn.solve();

        if (simple.finalNonOrthogonalIter())
        {
            psi = psiHbyAa - qEqn.flux();
        }
    }
*/

        fvScalarMatrix qEqn
        (
            fvm::laplacian(rAtV(), q) == fvc::div(psiHbyAa)
        );

        qEqn.setReference(qRefCell, qRefValue);

        qEqn.solve();

        psi = psiHbyAa - qEqn.flux();



    #include "adjointContinuityErrs.H"

    // Explicitly relax pressure for momentum corrector
    q.relax();

    // Momentum corrector
    V = HbyAa - rAtV()*fvc::grad(q);
    V.correctBoundaryConditions();
    fvOptions.correct(V);
}
