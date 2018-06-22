Rcyl = 5e-2;
Rout = 1;

cx = 0;
cy = 0;

Point(1) = {0, 0, 0};

Point(2) = {Rcyl, 0, 0};
Point(3) = {0, Rcyl, 0};
Point(4) = {-Rcyl, 0, 0};
Point(5) = {0, -Rcyl, 0};

Point(6) = {Rout, 0, 0};
Point(7) = {0, Rout, 0};
Point(8) = {-Rout, 0, 0};
Point(9) = {0, -Rout, 0};

Circle(10) = {2, 1, 3};
Circle(11) = {3, 1, 4};
Circle(12) = {4, 1, 5};
Circle(13) = {5, 1, 2};

Circle(14) = {6, 1, 7};
Circle(15) = {7, 1, 8};
Circle(16) = {8, 1, 9};
Circle(17) = {9, 1, 6};

Line(18) = {2, 6};
Line(19) = {3, 7};
Line(20) = {4, 8};
Line(21) = {5, 9};

Line Loop(30) = {18, 14, -19, -10};
Plane Surface(31) = {30};

Line Loop(32) = {19, 15, -20, -11};
Plane Surface(33) = {32};

Line Loop(34) = {20, 16, -21, -12};
Plane Surface(35) = {34};

Line Loop(36) = {21, 17, -18, -13};
Plane Surface(37) = {36};

Transfinite Line{10, 11, 12, 13} = 50;
Transfinite Line{14, 15, 16, 17} = 50;
Transfinite Line{18, 19, 20, 21} = 100;
Recombine Surface{31,33,35,37};

newEntities[] =
Extrude {0,0,1}
{
	Surface{31, 33, 35, 37};
	Layers{1};
	Recombine;
};

Physical Surface("frontAndBack") = {31, 33, 35, 37, newEntities[0], newEntities[6], newEntities[12], newEntities[18]};
Physical Surface("inf") = {newEntities[3], newEntities[9], newEntities[15], newEntities[21]};
//Physical Surface("inlet") = {newEntities[9], newEntities[15]};
//Physical Surface("outlet") = {newEntities[3], newEntities[21]};
Physical Surface("walls") = {newEntities[5], newEntities[11], newEntities[17], newEntities[23]};
Physical Volume(60) = {newEntities[1], newEntities[7], newEntities[13], newEntities[19]};

Mesh 3;
Save "cylinder.msh";
