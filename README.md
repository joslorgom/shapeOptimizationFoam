# Optimal Shape Design in External Flow

A natural application in the framework of shape optimization is the aerodynamic design of an airfoil. An object defined by a domain <img src="https://latex.codecogs.com/gif.latex?%5COmega_s%20%5Cin%20%5Cmathbb%7BR%7D%5Ed"> with boundary <img src="https://latex.codecogs.com/gif.latex?%5CGamma_s"> immersed in a fluid will experience a net force given by

<p align="center">
  <img src="https://latex.codecogs.com/gif.latex?F_i%20%3D%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%7D%20-%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cbm%7Bu%7D%5Cright%29%20%5C%2C%20n_j%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma%2C">
</p>

where <img src="https://latex.codecogs.com/gif.latex?%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cbm%7Bu%7D%5Cright%29%20%3D%20-p%20%5Cdelta_%7Bij%7D%20&plus;%202%5Cnu%20S_%7Bij%7D%5Cleft%28%5Cbm%7Bu%7D%5Cright%29"> is the stress tensor, <img src="https://latex.codecogs.com/gif.latex?p"> is the fluid pressure, <img src="https://latex.codecogs.com/gif.latex?%5Cnu"> is the kinematic viscosity, <img src="https://latex.codecogs.com/gif.latex?S_%7Bij%7D%5Cleft%28%5Cmathbf%7Bu%7D%5Cright%29%20%3D%20%5Cfrac%7B1%7D%7B2%7D%20%5Cleft%28%20%5Cpartial_j%20u_i%20&plus;%20%5Cpartial_i%20u_j%20%5Cright%29"> is the strain rate tensor, and <img src="https://latex.codecogs.com/gif.latex?%5Cmathbf%7Bu%7D%20%5Cin%20%5Cmathbb%7BR%7D%5Ed"> is the fluid velocity vector field. 

<p align="center">
  <img src="figs/fig1.png" width="400" height="320">
</p>

The force exerted by the fluid on the airfoil parallel to the fluid velocity at infinity is referred to as the drag force, whereas the force in perpendicular direction is often named the lift.

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?D%20%3D%20d%5ED_i%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%7D%20-%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cbm%7Bu%7D%5Cright%29%20%5C%2C%20n_j%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma%2C">
</p>

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?L%20%3D%20d%5EL_i%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%7D%20-%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cbm%7Bu%7D%5Cright%29%20%5C%2C%20n_j%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma.">
</p>

We look for the optimal shape in order to minimize the drag, as this force produces energy losses, and at the same time maximize the lift for a fixed airfoil volume. This can be expressed by means of the functional

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cmathcal%7BJ%7D%20%5Cleft%28%20%5Ctheta%20%5Cright%29%20%3D%20w%5ED%20D%20-%20w%5EL%20L%20%3D%20d_i%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%29%7D%20-%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cmathbf%7Bu%7D%5Cright%29n_j%20%5Cmathrm%7Bd%7D%20%5CGamma%2C">
</p>

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?d_i%20%3D%20w%5ED%20d%5ED_i%20-%20w%5EL%20d%5EL_i%2C">
</p>

where <img src="https://latex.codecogs.com/gif.latex?w%5ED"> and <img src="https://latex.codecogs.com/gif.latex?w%5EL"> are weighting factors for drag and lift forces, respectively, and with <img src="https://latex.codecogs.com/gif.latex?%5Ctheta%20%5Cin%20L%5E2%5Cleft%28%20%5CGamma_s%20%5Cright%29">. The state variables are subject to a set of constraints in the fluid domain <img src="https://latex.codecogs.com/gif.latex?%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29"> with boundary <img src="https://latex.codecogs.com/gif.latex?%5CGamma_f%20%3D%20%5CGamma_%7Bin%7D%20%5Ccup%20%5CGamma_%7Bout%7D%20%5Ccup%20%5CGamma_s%5Cleft%28%20%5Ctheta%20%5Cright%20%29%20%5Ccup%20%5CGamma_w">, namely the steady Navier-Stokes equations,

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20u_j%20%5Cpartial_j%20u_i%20-%20%5Cpartial_j%20%5Cleft%5B%20%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cmathbf%7Bu%7D%20%5Cright%29%20%5Cright%5D%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20%5Cpartial_j%20u_j%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20u_i%20%3D%20u%5E%5Cinfty_i%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7Bin%7D%2C%20%5C%5C%20u_i%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%20%5Ccup%20%5CGamma_w%2C%20%5C%5C%20%5Csigma_%7Bij%7D%20%5Cleft%28p%2C%20%5Cmathbf%7Bu%7D%20%5Cright%29%20n_j%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7Bout%7D%2C%20%5Cend%7Bcases%7D">
</p>

and to the volume constraint

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cleft%7C%20%5COmega_%7Bs%7D%20%5Cright%7C%20%3D%20%5COmega_0.">
</p>

The adjoint problem reads as

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20v_j%20%5Cpartial_i%20u_j%20-%20%5Cpartial_j%20%5Cleft%28%20u_j%20v_i%20%5Cright%29%20-%20%5Cpartial_j%20%5Cleft%5B%20%5Csigma_%7Bij%7D%20%5Cleft%28q%2C%20%5Cmathbf%7Bv%7D%20%5Cright%29%20%5Cright%5D%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20%5Cpartial_j%20v_j%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20v_i%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7Bin%7D%20%5Ccup%20%5CGamma_w%2C%20%5C%5C%20v_i%20%3D%20-d_i%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20%5Csigma_%7Bij%7D%20%5Cleft%28q%2C%20%5Cmathbf%7Bv%7D%20%5Cright%29%20n_j%20&plus;%20v_i%20u_j%20n_j%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7Bout%7D.%20%5Cend%7Bcases%7D">
</p>

The directional derivative of the functional is given by 

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cmathcal%7BD%7D_%7B%5Cdelta%20%5Ctheta%7D%20%5Cmathcal%7BJ%7D%20%3D%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%7D%20%5Cleft%5B%20r%20-%202%20%5Cnu%20S_%7Bij%7D%20%5Cleft%28%20%5Cmathbf%7Bv%7D%20%5Cright%29%20%5C%2C%20n_j%20%5C%2C%20n_k%20%5C%2C%20%5Cpartial_k%20u_i%20%5Cright%5D%20%5C%2C%20%5Cdelta%20%5Ctheta%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma%2C">
</p>

and the cost function descreases by choosing the normal displacement to the controlled boundary as

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cdelta%20%5Ctheta%20%5E%7B%5Cleft%28n%5Cright%29%7D%20%3D%20-%20%5Cleft%5B%20r%5E%7B%5Cleft%28n%5Cright%29%7D%20-%202%20%5Cnu%20S_%7Bij%7D%20%5Cleft%28%20%5Cmathbf%7Bv%7D%5E%7B%5Cleft%28n%5Cright%29%7D%20%5Cright%29%20%5C%2C%20n_j%5E%7B%5Cleft%28n%5Cright%29%7D%20%5C%20n_k%5E%7B%5Cleft%28n%5Cright%29%7D%20%5C%2C%20%5Cpartial_k%20u_i%5E%7B%5Cleft%28n%5Cright%29%7D%20%5Cright%5D.">
</p>

Hence,

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Ctheta%20%5E%7B%5Cleft%28n&plus;1%5Cright%29%7D%20%3D%20%5Ctheta%20%5E%7B%5Cleft%28n%5Cright%29%7D%20&plus;%20%5Cepsilon%20%5Cdelta%20%5Ctheta%20%5E%7B%5Cleft%28n%5Cright%29%7D%2C">
</p>

for a sufficiently small value of <img src="https://latex.codecogs.com/gif.latex?%5Cepsilon">.

The remaining Lagrange multiplier associated to the volume constraint is computed in order to ensure the volume conservation,

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?r%5E%7B%5Cleft%28n%5Cright%29%7D%20%3D%20%5Cfrac%7B1%7D%7B%5Cleft%7C%20%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%20%5Cright%7C%7D%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%7D%202%20%5Cnu%20S_%7Bij%7D%20%5Cleft%28%20%5Cmathbf%7Bv%7D%5E%7B%5Cleft%28n%5Cright%29%7D%20%5Cright%29%20n_j%5E%7B%5Cleft%28n%5Cright%29%7D%20n_k%5E%7B%5Cleft%28n%5Cright%29%7D%20%5Cpartial_k%20u_i%5E%7B%5Cleft%28n%5Cright%29%7D%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma.">
</p>

In summary, the shape optimization iteration is as follows:
* Solve the primal problem.
* Solve the adjoint problem with the previously computed state variables.
* Compute the Lagrange multiplier for the volume constraint.
* Compute the displacement field.
* Update the displacement field of the previous iteration.
* Perform the mesh motion.

## Getting Started

The solver must be compiled in the terminal. It is advisable to first clean previous compilations with

```
wclean
```

and then use

```
wmake
```

### Prerequisites

OpenFOAM C++ library must be installed in order to compile the code.

The OpenFOAM distribution provided by the [OpenFOAM Foundation](https://openfoam.org/) was used.

## Running a Case

The above shape optimization process has been implemented in the open-source C++ library OpenFOAM. The already existing solver _adjointShapeOptimizationFoam_ is a topological optimization routine that relies on a porosity variable and on the calculation of volume sensitivities to determine which regions of the domain must be blocked to the fluid passage in order to minimize a known functional. We have coded a new solver _shapeOptimizationFoam_ that takes some ideas from the aforementioned one, but which performs a shape optimization iteration instead by computing shape sensitivities.

<p align="center">
    <img src="/shapeOptimizationFoamCase/figs/fig1.png" width="400" height="320">
</p>

The solver has been tested in the minimization of the the cost function

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cmathcal%7BJ%7D%20%5Cleft%28%20%5Ctheta%20%5Cright%29%20%3D%20%5Cleft%28%20w%5ED%20d%5ED_i%20-%20w%5EL%20d%5EL_i%20%5Cright%29%20%5Cint_%7B%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%29%7D%20-%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cmathbf%7Bu%7D%5Cright%29n_j%20%5C%20%5Cmathrm%7Bd%7D%20%5CGamma%2C">
</p>

subject to

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20u_j%20%5Cpartial_j%20u_i%20-%20%5Cpartial_j%20%5Cleft%5B%20%5Csigma_%7Bij%7D%5Cleft%28p%2C%20%5Cmathbf%7Bu%7D%20%5Cright%29%20%5Cright%5D%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%29%20%5Cright%20%29%2C%20%5C%5C%20%5Cpartial_j%20u_j%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%29%20%5Cright%20%29%2C%20%5C%5C%20u_i%20%3D%20u%5E%5Cinfty_i%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7B%5Cinfty%7D%2C%20%5C%5C%20u_i%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%29%20%5Cright%20%29.%20%5C%5C%20%5Cend%7Bcases%7D">
</p>

The adjoint problem reads as

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20v_j%20%5Cpartial_i%20u_j%20-%20%5Cpartial_j%20%5Cleft%28%20u_j%20v_i%20%5Cright%29%20-%20%5Cpartial_j%20%5Cleft%5B%20%5Csigma_%7Bij%7D%20%5Cleft%28q%2C%20%5Cmathbf%7Bv%7D%20%5Cright%29%20%5Cright%5D%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20%5Cpartial_j%20v_j%20%3D%200%20%26%20%5Ctext%7Bin%20%7D%20%5COmega_f%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29%2C%20%5C%5C%20v_i%20%3D%200%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_%7B%5Cinfty%7D%2C%20%5C%5C%20v_i%20%3D%20-d_i%20%26%20%5Ctext%7Bon%20%7D%20%5CGamma_s%20%5Cleft%28%20%5Ctheta%20%5Cright%20%29.%20%5C%5C%20%5Cend%7Bcases%7D">
</p>

In order to run the solver move to the case folder _shapeOptimizationFoamCase_ and type in the command line

```
./Allprepare

shapeOptimizationFoam
```

The solver has been run for three different Reynolds numbers and the cost functional value has been normalized with

<p align="center">
    <img src="https://latex.codecogs.com/gif.latex?%5Cfrac%7B1%7D%7B2%7D%20%5Crho%20U_%7B%5Cinfty%7D%5E2%20D%20e">
</p>

where <img src="https://latex.codecogs.com/gif.latex?D"> and <img src="https://latex.codecogs.com/gif.latex?e"> are the cylinder diameter and thickness, respectively.

<p align="center">
    <img src="/shapeOptimizationFoamCase/figs/fig2.png">
</p>

### Warning

It might be needed to use 

```
sed -i -e 's/\r$//' filename
```

and

```
chmod +x filename
```

in order to be able to execute 

```
./filename
```

## References

* Antony Jameson. Aerodynamic design via control theory. _Journal of scientific computing_, 3(3):233–260, 1988.
* Antony Jameson and Luigi Martinelli. Aerodynamic shape optimization techniques based on control theory. In _Computational Mathematics Driven by Industrial Problems_, pages 151–221. Springer, 2000.
* Antony Jameson and James Reuther. Control theory based airfoil design using the euler equations. In _5th Symposium on Multidisciplinary Analysis and Optimization_, page 4272, 1994.
* Bijan Mohammadi and Olivier Pironneau. Mesh adaption and automatic differentiation in a cad-free framework for optimal shape design. _International Journal for Numerical Methods in Fluids_, 30(2):127–136, 1999.
* Bijan Mohammadi and Olivier Pironneau. _Applied shape optimization for fluids_. Oxford University Press, 2010.
* C. Othmer. A continuous adjoint formulation for the computation of topological and surface sensitivities of ducted flows. _International Journal for Numerical Methods in Fluids_, 58(8):861–877, 2008.
* C. Othmer, E. Papoutsis-Kiachagias, and K. Haliskos. CFD optimization via sensitivity-based shape morphing. In _Proceedings of the 4th ANSA & μETA Internat. Conf., Thessaloniki, Greece, BETA CAE Systems SA_, 2011.
* Carsten Othmer. Adjoint methods for car aerodynamics. _Journal of Mathematics in Industry_, 4(1):6, 2014.
* Carsten Othmer, Eugene de Villiers, and Henry Weller. Implementation of a continuous adjoint for topology optimization of ducted flows. In _18th AIAA Computational Fluid Dynamics Conference_, page 3947, 2007.
* Carsten Othmer and Thorsten Grahs. Approaches to fluid dynamic optimization in the car development process. In _International Conference on Evolutionary and Deterministic Methods for Design, Optimization and Control With Applications to Industrial and Societal Problems_, 2005.
* Carsten Othmer, Thomas Kaminski, and Ralf Giering. Computation of topological sensitivities in fluid dynamics: cost function versatility. In _ECCOMAS CFD 2006: Proceedings of the European Conference on Computational Fluid Dynamics, Egmond aan Zee, The Netherlands, September 5-8, 2006_. Citeseer, 2006.
* Olivier Pironneau. _Optimal shape design for elliptic systems_. Springer Science & Business Media, 2012.
* James Reuther and Antony Jameson. Aerodynamic shape optimization of wing and wing-body configurations using control theory. In _33rd Aerospace Sciences Meeting and Exhibit_, page 123, 1995.
* James Reuther, Antony Jameson, James Farmer, Luigi Martinelli, and David Saunders. Aerodynamic shape optimization of complex aircraft configurations via an adjoint formulation. In _34th Aerospace Sciences Meeting and Exhibit_, page 94, 1996.
* James J Reuther, Antony Jameson, Juan J Alonso, Mark J Rimlinger, and David Saunders. Constrained multipoint aerodynamic shape optimization using an adjoint formulation and parallel computers, part 1. _Journal of aircraft_, 36(1):51–60, 1999.
* J. Simon. Diferenciación de problemas de contorno respecto del dominio. Technical report, Universidad de Sevilla, Facultad de Matemáticas, Departamento de Análisis Matemático, 1989.
* Orlando Soto and Rainald Löhner. On the computation of flow sensitivities from boundary integrals. _AIAA paper_, 112:2004, 2004.
* Orlando Soto, Rainald Löhner, and Chi Yang. An adjoint-based design methodology for CFD problems. _International Journal of Numerical Methods for Heat & Fluid Flow_, 14(6):734–759, 2004.
* Schumacher Thomas, Othmer Carsten, et al. Adjoint optimization for vehicle external aerodynamics. _International Journal of Automotive Engineering_, 7(1):1–7, 2016.
* Henk Kaarle Versteeg and Weeratunge Malalasekera. _An introduction to computational fluid dynamics: the finite volume method_. Pearson Education, 2007.
* F. Feppon, G. Allaire, F. Bordeu, J. Cortial, and C. Dapogny. Shape optimization of a coupled thermal fluid-structure problem in a level set mesh evolution framework, 2018.

