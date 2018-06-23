Rcyl = 0.05;
Rout = 1;

cx = 0;
cy = 0;

L = 0.2;

N = 20;
//sigma = 1.05;
sigma = 1;

Point(1) = {0, 0, 0};

Point(2) = {Rcyl, 0, 0};
Point(3) = {Rcyl/Sqrt(2), Rcyl/Sqrt(2), 0};
Point(4) = {0, Rcyl, 0};
Point(5) = {-Rcyl/Sqrt(2), Rcyl/Sqrt(2), 0};
Point(6) = {-Rcyl, 0, 0};
Point(7) = {-Rcyl/Sqrt(2), -Rcyl/Sqrt(2), 0};
Point(8) = {0, -Rcyl, 0};
Point(9) = {Rcyl/Sqrt(2), -Rcyl/Sqrt(2), 0};

Circle(101) = {2, 1, 3};
Circle(102) = {3, 1, 4};
Circle(103) = {4, 1, 5};
Circle(104) = {5, 1, 6};
Circle(105) = {6, 1, 7};
Circle(106) = {7, 1, 8};
Circle(107) = {8, 1, 9};
Circle(108) = {9, 1, 2};

Point(10) = {Rout, 0, 0};
Point(11) = {Rout/Sqrt(2), Rout/Sqrt(2), 0};
Point(12) = {0, Rout, 0};
Point(13) = {-Rout/Sqrt(2), Rout/Sqrt(2), 0};
Point(14) = {-Rout, 0, 0};
Point(15) = {-Rout/Sqrt(2), -Rout/Sqrt(2), 0};
Point(16) = {0, -Rout, 0};
Point(17) = {Rout/Sqrt(2), -Rout/Sqrt(2), 0};

Circle(109) = {10, 1, 11};
Circle(110) = {11, 1, 12};
Circle(111) = {12, 1, 13};
Circle(112) = {13, 1, 14};
Circle(113) = {14, 1, 15};
Circle(114) = {15, 1, 16};
Circle(115) = {16, 1, 17};
Circle(116) = {17, 1, 10};

Line(201) = {2, 10};
Line(202) = {3, 11};
Line(203) = {4, 12};
Line(204) = {5, 13};
Line(205) = {6, 14};
Line(206) = {7, 15};
Line(207) = {8, 16};
Line(208) = {9, 17};

Transfinite Line{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116} = 10;
Transfinite Line{201, 202, 203, 204, 205, 206, 207, 208} = 90 Using Progression 1;

Line Loop(51) = {201,109,-202,-101};
Plane Surface(81) = {51};
Transfinite Surface{81};
Recombine Surface{81};

Line Loop(52) = {202, 110, -203, -102};
Plane Surface(82) = {52};
Transfinite Surface{82};
Recombine Surface{82};

Line Loop(53) = {203, 111, -204, -103};
Plane Surface(83) = {53};
Transfinite Surface{83};
Recombine Surface{83};

Line Loop(54) = {204, 112, -205, -104};
Plane Surface(84) = {54};
Transfinite Surface{84};
Recombine Surface{84};

Line Loop(55) = {205, 113, -206, -105};
Plane Surface(85) = {55};
Transfinite Surface{85};
Recombine Surface{85};

Line Loop(56) = {206, 114, -207, -106};
Plane Surface(86) = {56};
Transfinite Surface{86};
Recombine Surface{86};

Line Loop(57) = {207, 115, -208, -107};
Plane Surface(87) = {57};
Transfinite Surface{87};
Recombine Surface{87};

Line Loop(58) = {208, 116, -201, -108};
Plane Surface(88) = {58};
Transfinite Surface{88};
Recombine Surface{88};

newEntities[] =
Extrude {0,0,0.01}
{
	Surface{81,82,83,84,85,86,87,88};
	Layers{1};
	Recombine;
};

Physical Surface("frontAndBack") = {81,82,83,84,85,86,87,88,newEntities[0],newEntities[6],newEntities[12],newEntities[18],newEntities[24],newEntities[30],newEntities[36],newEntities[42]};
Physical Surface("inf") = {newEntities[3],newEntities[9],newEntities[15],newEntities[21],newEntities[27],newEntities[33],newEntities[39],newEntities[45]};
Physical Surface("walls") = {newEntities[5],newEntities[11],newEntities[17],newEntities[23],newEntities[29],newEntities[35],newEntities[41],newEntities[47]};
Physical Volume(60) = {newEntities[1],newEntities[7],newEntities[13],newEntities[19],newEntities[25],newEntities[31],newEntities[37],newEntities[43]};

Mesh 3;
Save "cylinder.msh";
