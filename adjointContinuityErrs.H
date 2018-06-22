{
    scalar sumLocalContErr = runTime.deltaTValue()*
        mag(fvc::div(psi))().weightedAverage(mesh.V()).value();

    scalar globalContErr = runTime.deltaTValue()*
        fvc::div(psi)().weightedAverage(mesh.V()).value();
    cumulativeAdjointContErr += globalContErr;

    Info<< "Adjoint continuity errors : sum local = " << sumLocalContErr
        << ", global = " << globalContErr
        << ", cumulative = " << cumulativeAdjointContErr
        << endl;
}
