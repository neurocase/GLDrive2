
//degdToRad


const double PEYE = 3.141592653589793;

double DegToRad(double deg){
double rad = deg * (PEYE/180);
return rad;
}
	
	
double RadToDeg(double rad){
double deg = rad * (180/PEYE);
return deg;
}
