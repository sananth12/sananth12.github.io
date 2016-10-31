/**
   Anantha Natarajan S
   http://ananth.co.in
 **/

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

// Box size
float L = 4.0;
// Number of particles
int N = 2;
// Radius
float R = 1.0;
// Points inside
int found = 0;


struct Point{
  float x,y,z;
  
  Point(){
    x = 0;
    y = 0;
    z = 0;
  }

  Point(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
  }

  void print(){
    cout<<x<<" "<<y<<" "<<z<<endl;
  }
};

// Particles inside box
Point inside[100];

Point generateP(float L) {
 
  // Generate between 1-L so it always fits inside
  float x = rand() * L ;
  float y = rand() * L ;
  float z = rand() * L ;

  Point p(x,y,z);
  
  return p;
}

bool fitinsideBox(Point P) {
  // Logic to check if particle will fit inside box
  // Not necessary as already generated points follow rule
  return true;
  
  if ((P.x - R < 0)|| (P.y - R < 0) ||( P.z - R < 0)){
    //  cout<<P.x<<"~";
    return false;
  }
  if((P.x + R) > L || (P.y + R > L) || (P.z + R > L)){
    cout<<( R)<<"%"<<L<<endl;
    return false;
  }
  // Any other condition?

  return true;
}


// Check if given p collides with particles inside box
bool collide(Point p) {
  
  for (int i = 0; i < found; i++) {
    Point q = inside[i];
    
    float dx = q.x - p.x;
    dx *= dx;
    float dy = q.y - p.y;
    dy *= dy;
    float dz = q.z - p.z;
    dz *= dz;

    float r_sumsq = 4;
    //cout<< "Dist.^2 between points:"<< (dx + dy + dz) << endl;
    // Collides?
    if(r_sumsq >= (dz + dx + dy)){
      return true;
    }
  }

  // If flow reaches here, it doesn't collide
  return false;
}
 
int main(){
  // Seed the random number generetor
  srand(time(NULL));

  L = 100;
  R = 1;
  N = 100;
  Point p;

  while(found < N) {
    
    p = generateP(L);
    
    // cout<<collide(p)<<endl;
    //    int x;
    //    cin>>x;

    if(collide(p))
      continue;
    
    inside[found] = p;
    found ++;
    
    cout<<"Found "<<found<<endl;
    //p.print();
  }
  
  cout<<"Points are:\n";
  for(int i = 0; i < found; i++){
    inside[i].print();
  }
  
  return 0;
}
