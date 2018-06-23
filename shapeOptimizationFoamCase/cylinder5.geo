Rcyl = 0.05;
Rout = 1;

cx = 0;
cy = 0;

Point(1) = {0, 0, 0};

Point(2) = {Rcyl/Sqrt(2), Rcyl/Sqrt(2), 0};
Point(3) = {-Rcyl/Sqrt(2), Rcyl/Sqrt(2), 0};
Point(4) = {-Rcyl/Sqrt(2), -Rcyl/Sqrt(2), 0};
Point(5) = {Rcyl/Sqrt(2), -Rcyl/Sqrt(2), 0};

Point(6) = {Rout/Sqrt(2), Rout/Sqrt(2), 0};
Point(7) = {-Rout/Sqrt(2), Rout/Sqrt(2), 0};
Point(8) = {-Rout/Sqrt(2), -Rout/Sqrt(2), 0};
Point(9) = {Rout/Sqrt(2), -Rout/Sqrt(2), 0};

Circle(11) = {2, 1, 3};
Circle(12) = {3, 1, 4};
Circle(13) = {4, 1, 5};
Circle(14) = {5, 1, 2};

Circle(21) = {6, 1, 7};
Circle(22) = {7, 1, 8};
Circle(23) = {8, 1, 9};
Circle(24) = {9, 1, 6};

Line(31) = {2, 6};
Line(32) = {3, 7};
Line(33) = {4, 8};
Line(34) = {5, 9};

Transfinite Line{11, 13, 21, 23} = 40;
Transfinite Line{12, 14, 22, 24} = 40 Using Bump 5; 
Transfinite Line{31, 32, 33, 34} = 140 Using Progression 1;

Line Loop(51) = {31, 21, -32, -11};
Plane Surface(81) = {51};
Transfinite Surface{81};
Recombine Surface{81};

Line Loop(52) = {32, 22, -33, -12};
Plane Surface(82) = {52};
Transfinite Surface{82};
Recombine Surface{82};

Line Loop(53) = {33, 23, -34, -13};
Plane Surface(83) = {53};
Transfinite Surface{83};
Recombine Surface{83};

Line Loop(54) = {34, 24, -31, -14};
Plane Surface(84) = {54};
Transfinite Surface{84};
Recombine Surface{84};

newEntities[] =
Extrude {0,0,0.01}
{
	Surface{81,82,83,84};
	Layers{1};
	Recombine;
};

Physical Surface("frontAndBack") = {81,82,83,84,newEntities[0],newEntities[6],newEntities[12],newEntities[18]};
Physical Surface("inf") = {newEntities[3],newEntities[9],newEntities[15],newEntities[21]};
Physical Surface("walls") = {newEntities[5],newEntities[11],newEntities[17],newEntities[23]};
Physical Volume(60) = {newEntities[1],newEntities[7],newEntities[13],newEntities[19]};

Mesh 3;
Save "cylinder.msh";
