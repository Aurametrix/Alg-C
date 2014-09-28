// Gets all the vertices for Rectangle 1 and stores them in an array -> arrRect1
// point 1 x: arrRect1[0], point 1 y: arrRect1[1] and so on...
// Gets all the vertices for Rectangle 2 and stores them in an array -> arrRect2

// rotated edge of point a, rect 1
int rot_x, rot_y;
rot_x = -arrRect1[3];
rot_y = arrRect1[2];
// point on rotated edge
int pnt_x, pnt_y;
pnt_x = arrRect1[2]; 
pnt_y = arrRect1[3];
// test point, a from rect 2
int tst_x, tst_y;
tst_x = arrRect2[0];
tst_y = arrRect2[1];

int value;
value = (rot_x * (tst_x - pnt_x)) + (rot_y * (tst_y - pnt_y));
cout << "Value: " << value;
