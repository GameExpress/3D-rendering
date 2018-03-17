#include <Arduboy2.h>
Arduboy2 arduboy;
#define X_OFFSET 48
#define Y_OFFSET 28
#define POINTNUM 16

int16_t nodes[POINTNUM][4] = {{0,0,0,1},{10,0,0,2},{10,0,10,3},{0,0,10,4},{0,0,0,5},{0,10,0,6},{10,10,0,7},{10,10,10,8},{0,10,10,9},{0,10,0,9},{10,0,0,11},{10,10,0,11},{10,0,10,13},{10,10,10,13},{0,0,10,15},{0,10,10,15}};
//Every node has 4 values:
//0 = X
//1 = Y
//2 = Z
//3 = Connection to another node


void setup() {
  arduboy.begin();
  arduboy.clear();
}

void loop() {
  if(!(arduboy.nextFrame())) return;
  arduboy.clear();
  for(uint8_t x; x < POINTNUM; x++) {
    arduboy.drawLine(X_OFFSET + nodes[x][0] + nodes[x][2] + nodes[x][1] / 5,Y_OFFSET + nodes[x][1] - nodes[x][2] / 2,X_OFFSET + nodes[nodes[x][3]][0] + nodes[nodes[x][3]][2] + nodes[nodes[x][3]][1] / 5,Y_OFFSET + nodes[nodes[x][3]][1] - nodes[nodes[x][3]][2] / 2,WHITE);
  }arduboy.display();
}
