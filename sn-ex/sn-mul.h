// SN MUL - multiplication

#define m 15
#define n 16

int b[m][n]={
{1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0},
{-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{-1,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0},
{0,1,0,0,-1,-1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,-1,-1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,-1,-1,-1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,-1,-1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,-1,-1,-1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,1,0,-1,0,0,0,0,0,-1,0},
{0,0,0,0,0,0,0,0,0,-1,0,0,0,0,1,-1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0},
};
int d[m][n]={
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0}
};
int r[n][n]={
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int mu[m]={1, 0, 1135, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 13864};

// end SN MUL
