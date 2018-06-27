Rcyl = 0.05;
Rout = 1;

cx = 0;
cy = 0;

Point(1) = {0, 0, 0};

Point(2) = {3.14158/2*Rcyl, 0, 0};
Point(3) = {0, Rcyl, 0};
Point(4) = {-Rcyl/Sqrt(2), Rcyl/Sqrt(2), 0};
Point(5) = {-Rcyl/Sqrt(2), -Rcyl/Sqrt(2), 0};
Point(6) = {0, -Rcyl, 0};
Point(7) = {Rout, 0, 0};
Point(8) = {0, Rout, 0};
Point(9) = {-Rout/Sqrt(2), Rout/Sqrt(2), 0};
Point(10) = {-Rout/Sqrt(2), -Rout/Sqrt(2), 0};
Point(11) = {0, -Rout, 0};

Line(21) = {2, 7};
Circle(22) = {7, 1, 8};
Line(23) = {8, 3};
Line(24) = {3, 2};
Circle(25) = {8, 1, 9};
Line(26) = {9, 4};
Circle(27) = {4, 1, 3};
Circle(28) = {9, 1, 10};
Line(29) = {10, 5};
Circle(30) = {5, 1, 4};
Circle(31) = {10, 1, 11};
Line(32) = {11, 6};
Circle(33) = {6, 1, 5};
Circle(34) = {11, 1, 7};
Line(35) = {2, 6};

Transfinite Line{21, 23, 26, 29, 32} = 151;
Transfinite Line{22, 24, 34, 35} = 41;
Transfinite Line{25, 27, 31, 33} = 21;
Transfinite Line{28, 30} = 41;

Line Loop(51) = {21, 22, 23, 24};
Plane Surface(81) = {51};
Transfinite Surface{81};
Recombine Surface{81};

Line Loop(52) = {-23, 25, 26, 27};
Plane Surface(82) = {52};
Transfinite Surface{82};
Recombine Surface{82};

Line Loop(53) = {-26, 28, 29, 30};
Plane Surface(83) = {53};
Transfinite Surface{83};
Recombine Surface{83};

Line Loop(54) = {-29, 31, 32, 33};
Plane Surface(84) = {54};
Transfinite Surface{84};
Recombine Surface{84};

Line Loop(55) = {-32, 34, -21, 35};
Plane Surface(85) = {55};
Transfinite Surface{85};
Recombine Surface{85};

newEntities[] =
Extrude {0,0,0.01}
{
	Surface{81,82,83,84,85};
	Layers{1};
	Recombine;
};

Physical Surface("frontAndBack") = {81,82,83,84,85,newEntities[0],newEntities[6],newEntities[12],newEntities[18],newEntities[24]};
Physical Surface("inf") = {newEntities[3],newEntities[9],newEntities[15],newEntities[21],newEntities[27]};
Physical Surface("walls") = {newEntities[5],newEntities[11],newEntities[17],newEntities[23],newEntities[29]};
Physical Volume(60) = {newEntities[1],newEntities[7],newEntities[13],newEntities[19],newEntities[25]};

Mesh 3;
Save "cylinder.msh";
