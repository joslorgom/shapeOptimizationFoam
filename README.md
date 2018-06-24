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


