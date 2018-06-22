Rcyl = 5e-2;
Rout = 1;

cx = 0;
cy = 0;

L = 0.2;

N = 30;
//sigma = 1.05;
sigma = 1;

Point(1) = {0, 0, 0};

Point(2) = {Rcyl, 0, 0};
Point(3) = {0, Rcyl, 0};
Point(4) = {-Rcyl, 0, 0};
Point(5) = {0, -Rcyl, 0};

Point(6) = {Rout, 0, 0};
Point(7) = {0, Rout, 0};
Point(8) = {-Rout, 0, 0};
Point(9) = {0, -Rout, 0};

Point(10) = {L, 0, 0};
Point(11) = {0, L, 0};
Point(12) = {-L, 0, 0};
Point(13) = {0, -L, 0};

Circle(14) = {2, 1, 3};
Circle(15) = {3, 1, 4};
Circle(16) = {4, 1, 5};
Circle(17) = {5, 1, 2};

Line(18) = {10, 11};
Line(19) = {11, 12};
Line(20) = {12, 13};
Line(21) = {13, 10};

Circle(22) = {6, 1, 7};
Circle(23) = {7, 1, 8};
Circle(24) = {8, 1, 9};
Circle(25) = {9, 1, 6};

Line Loop(50) = {14, 15, 16, 17, 18, 19, 20, 21};
Plane Surface(51) = {50};

Line Loop(52) = {18, 19, 20, 21, 22, 23, 24, 25};
Plane Surface(53) = {52};

//Transfinite Line{14, 15, 16, 17} = 50;
Transfinite Line{14} = N Using Progression sigma;
Transfinite Line{15} = N Using Progression 1/sigma;
Transfinite Line{16} = N Using Progression sigma;
Transfinite Line{17} = N Using Progression 1/sigma;
Transfinite Line{18, 19, 20, 21} = 50;
Transfinite Line{22, 23, 24, 25} = 50;
//Recombine Surface{51};

newEntities[] =
Extrude {0,0,0.01}
{
	Surface{51, 53};
	Layers{1};
	Recombine;
};

Physical Surface("frontAndBack") = {51, 53, newEntities[0], newEntities[10]};
Physical Surface("inf") = {newEntities[16], newEntities[17], newEntities[18], newEntities[19]};
//Physical Surface("inlet") = {newEntities[9], newEntities[15]};
//Physical Surface("outlet") = {newEntities[3], newEntities[21]};
Physical Surface("walls") = {newEntities[2], newEntities[3], newEntities[4], newEntities[5]};
Physical Volume(60) = {newEntities[1],newEntities[11]};

Mesh 3;
Save "cylinder.msh";
