#include<math.h>
#include<stdlib.h>
#include<iostream> 
#include<fstream>



float clamp(float x, float lowerlimit, float upperlimit) {
  if (x < lowerlimit)
    x = lowerlimit;
  if (x > upperlimit)
    x = upperlimit;
  return x;
}
float smoothstep(float edge0, float edge1, float x) {
  // Scale, bias and saturate x to 0..1 range
  x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0); 
  // Evaluate polynomial
  return x * x * (3 - 2 * x);
}


float sqr(float a){return a*a;}
class vec3 {

public:
	float e[3];
    vec3(){}
    vec3(float e0, float e1, float e2){ e[0] = e0; e[1]=e1; e[2]=e2;}
    float x() const{ return e[0]; }
    float y() const{ return e[1]; }
    float z() const{ return e[2]; }

    float r() const{ return e[0]; }
    float g() const{ return e[1]; }
    float b() const{ return e[2]; }

    const vec3& operator + () const { return *this; }
    vec3 operator -() const { return vec3 (-e[0],-e[1],-e[2]);}
    float operator[](int i) const { return e[i] ; };
    float& operator[](int i ) {return e[i];}
    vec3& operator +=(const vec3 &v);
    vec3& operator -=(const vec3 &v);
    vec3& operator *=(const vec3 &v);
    vec3& operator /=(const vec3 &v);
    vec3& operator *=(const float t);
    vec3& operator /=(const float t);

    float length() const {
    	return sqrt(sqr(e[0]) +sqr(e[1]) +sqr(e[3]));
    }
    float squared_length() const {
    	return sqr(e[0])+sqr(e[1])+sqr(e[2]);
    }
    void make_unit_vector();

};

std::istream& operator >>(std::istream &is ,vec3 &t){
	is >> t.e[0] >>t.e[1] >> t.e[2];
	return is;
}

std::ostream& operator<<(std::ostream &os , const vec3 &t){
	os << t.e[0] << " " << t.e[1] << t.e[2];
	return os;
}

void vec3::make_unit_vector(){
	float k = 1.0/sqrt(sqr(e[0])+sqr(e[1]) + sqr(e[2]));
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}


vec3 operator +(const vec3 &v1, const vec3 &v2){
	return vec3(v1.e[0] + v2.e[0] , v1.e[1] + v2.e[1] , v1.e[2] + v2.e[2]);
}

vec3 operator -(const vec3 &v1, const vec3 &v2){
	return vec3(v1.e[0] - v2.e[0] , v1.e[1] - v2.e[1] , v1.e[2] - v2.e[2]);
}

vec3 operator *(const vec3 &v1, const vec3 &v2){
	return vec3(v1.e[0] * v2.e[0] , v1.e[1] * v2.e[1] , v1.e[2] * v2.e[2]);
}

vec3 operator /(const vec3 &v1, const vec3 &v2){
	return vec3(v1.e[0] / v2.e[0] , v1.e[1] / v2.e[1] , v1.e[2] / v2.e[2]);
}


vec3 operator *(const vec3 &v, float t){
	return vec3(v.e[0] * t , v.e[1] * t , v.e[2] * t );

}

vec3 operator *(float t , const vec3 &v){
	return vec3(v.e[0] * t , v.e[1] * t , v.e[2] * t );

}

vec3 operator /(const vec3 &v, float t){
	return vec3(v.e[0] / t , v.e[1] / t , v.e[2] / t );
}

float dot(const vec3 &v1 , const vec3 &v2){
	return v1.e[0] *v2.e[0] + v1.e[1] * v2.e[1] + v2.e[2] * v2.e[2];
}

vec3 cross (const vec3 &v1 , const vec3 &v2){
	return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
				-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
				v1.e[0]*v2.e[1] -v1.e[1] *v2.e[0]);
}

vec3& vec3:: operator +=(const vec3 &v){
	e[0]+=v.e[0];
	e[1]+=v.e[1];
	e[2]+=v.e[2];

	return *this;
}

vec3& vec3:: operator -=(const vec3 &v){
	e[0]-=v.e[0];
	e[1]-=v.e[1];
	e[2]-=v.e[2];

	return *this;
}

vec3& vec3:: operator /=(const vec3 &v){
	e[0]/=v.e[0];
	e[1]/=v.e[1];
	e[2]/=v.e[2];

	return *this;
}

vec3& vec3:: operator *=(const vec3 &v){
	e[0]*=v.e[0];
	e[1]*=v.e[1];
	e[2]*=v.e[2];

	return *this;
}
vec3& vec3:: operator *=(const float t){
	e[0]*=t;
	e[1]*=t;
	e[2]*=t;

	return *this;	
}

vec3& vec3:: operator /=(const float t){
	e[0]/=t;
	e[1]/=t;
	e[2]/=t;
	return *this;	

}

vec3 unit_vector(vec3 v){
	return v / v.length();
}

float min(float a , float b){
	if(b < a)
		return b;
	else if(a < b ) return a;
	else return a ;

}
float length(vec3 v){
	return sqrt(sqr(v.x())+ sqr(v.y())+sqr(v.z()));

}
vec3 normalize(vec3 v){
	return vec3(v.x()/length(v),v.y()/length(v),v.z()/length(v));
}