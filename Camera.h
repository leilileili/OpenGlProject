float upx=0.0f,upy=1.0f,upz=0.0f;
 float _angle = 30.0f;
 float _cameraAngle = 0.0f;
  bool lbuttonDown;
 int direction;
 
void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(xx, yy, zz,
            xx + lx, yy + ly, zz + lz,
            0.0f, 1.0f, 0.0f);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear Screen And Depth Buffer
}

void moveMeFlat(int i) {
    xx = xx + i * (lx)*0.1;
    zz = zz + i * (lz)*0.1;
    glLoadIdentity();
    gluLookAt(xx, yy, zz,
            xx + lx, yy + ly, zz + lz,
            0.0f, 1.0f, 0.0f);
}

void moveMeAroundRight(int i) {
    
    ///////z is mines
    if(lx < 0.2 && lx >= 0 && lz <= 1 && lz <= 0){
       x = x + i+4 * (lx)*0.1;
    }else if(lx < 0.4 && lx >0 && lz <= 0){
        zz = zz + i/3 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }   
    else if(lx < 0.6 && lx > 0.4 && lz <= 0){
        zz = zz + i/2 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }else if(lx < 0.8 && lx > 0.6 && lz <= 0){
        zz = zz + i/1.5 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }else if(lx <= 1.0 && lx > 0.8 && lz <= 0){
        zz = zz + i+1 * (lz)*0.1;
        
    }else if(lx <= 0 && lx >= -0.2 && lz <= 0){
        xx = xx + i+4 * (lx)*0.1;
    }else if(lx <= -0.2 && lx >= -0.4 && lz <= 0){
        zz = zz - i/3 * (lz)*0.1;
        xx = xx + i+2 * (lx)*0.1;
    }else if(lx <= -0.4 && lx >= -0.6 && lz <= 0){
        zz = zz - i/2 * (lz)*0.1;
        xx = xx + i+1 * (lx)*0.1;
    }else if(lx <= -0.6 && lx >= -0.8 && lz <= 0){
        zz = zz + i * (lz)*0.1;
        xx = xx - i/2 * (lx)*0.1;
    }else if(lx <= -0.8 && lx >= -1.0 && lz <= 0){
        zz = zz - i+1 * (lz)*0.1;
    }
    /// z is plus
    else if(lx < 0.2 && lx >= 0 && lz <= 1 && lz >= 0){
       xx = xx - i+4 * (lx)*0.1;
    }else if(lx < 0.4 && lx >0 && lz >= 0){
        zz = zz + i/3 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }   
    else if(lx < 0.6 && lx > 0.4 && lz >= 0){
        zz = zz + i/2 * (lz)*0.1;
        x = x - i * (lx)*0.1;
    }else if(lx < 0.8 && lx > 0.6 && lz >= 0){
        zz = zz + i/1.5 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }else if(lx <= 1.0 && lx > 0.8 && lz >= 0){
        zz = zz + i+1 * (lz)*0.1;
        
    }else if(lx <= 0 && lx >= -0.2 && lz >= 0){
        xx = xx - i+4 * (lx)*0.1;
    }else if(lx <= -0.2 && lx >= -0.4 && lz >= 0){
        zz = zz + i/3 * (lz)*0.1;
        xx = xx - i+2 * (lx)*0.1;
    }else if(lx <= -0.4 && lx >= -0.6 && lz >= 0){
        zz = zz + i/2 * (lz)*0.1;
        xx = xx - i+1 * (lx)*0.1;
    }else if(lx <= -0.6 && lx >= -0.8 && lz >= 0){
        zz = zz - i * (lz)*0.1;
        xx = xx + i/2 * (lx)*0.1;
    }else if(lx <= -0.8 && lx >= -1.0 && lz >= 0){
        zz = zz - i+1 * (lz)*0.1;
    }
    ///////////////////////////
    
    cout<<"XX value is " <<x<<"\n";
    cout<<"LYYY value is " <<ly<<"\n";
    cout<<"LXXX value is " <<lx<<"\n";
    cout<<"LZZZ value is " <<lz<<"\n";
    glLoadIdentity();
    gluLookAt(xx, yy, zz,
            xx+ lx, yy + ly, zz + lz,
            0.0f, 1.0f, 0.0f);
}

void moveMeAroundLeft(int i) {
    
    ///////z is mines
    if(lx < 0.2 && lx >= 0 && lz <= 1 && lz <= 0){
       x = x - i+4 * (lx)*0.1;
    }else if(lx < 0.4 && lx >0 && lz <= 0){
        zz = zz - i/3 * (lz)*0.1;
        xx = xx + i * (lx)*0.1;
    }   
    else if(lx < 0.6 && lx > 0.4 && lz <= 0){
        zz = zz + i/2 * (lz)*0.1;
        xx = xx - i * (lx)*0.1;
    }else if(lx < 0.8 && lx > 0.6 && lz <= 0){
        zz = zz + i/1.5 * (lz)*0.1;
        xx = xx + i * (lx)*0.1;
    }else if(lx <= 1.0 && lx > 0.8 && lz <= 0){
        zz = zz - i+0.5 * (lz)*0.1;
        
    }else if(lx <= 0 && lx >= -0.2 && lz <= 0){
        xx = xx - i+4 * (lx)*0.1;
    }else if(lx <= -0.2 && lx >= -0.4 && lz <= 0){
        zz = zz + i/3 * (lz)*0.1;
        xx = xx - i+2 * (lx)*0.1;
    }else if(lx <= -0.4 && lx >= -0.6 && lz <= 0){
        zz = zz - i/2 * (lz)*0.1;
        xx = xx - i+0.5 * (lx)*0.1;
    }else if(lx <= -0.6 && lx >= -0.8 && lz <= 0){
        zz = zz - i * (lz)*0.1;
        xx = xx + i/2 * (lx)*0.1;
    }else if(lx <= -0.8 && lx >= -1.0 && lz <= 0){
        zz =zz + i+1 * (lz)*0.1;
    }
    /// z is plus
    else if(lx < 0.2 && lx >= 0 && lz <= 1 && lz >= 0){
       xx = xx + i+4 * (lx)*0.1;
    }else if(lx < 0.4 && lx >0 && lz >= 0){
        zz = zz - i/3 * (lz)*0.1;
        xx = xx + i * (lx)*0.1;
    }   
    else if(lx < 0.6 && lx > 0.4 && lz >= 0){
        zz = zz - i/2 * (lz)*0.1;
        xx = xx + i * (lx)*0.1;
    }else if(lx < 0.8 && lx > 0.6 && lz >= 0){
        zz = zz - i/1.5 * (lz)*0.1;
        xx = xx + i * (lx)*0.1;
    }else if(lx <= 1.0 && lx > 0.8 && lz >= 0){
        zz = zz - i+1 * (lz)*0.1;
        
    }else if(lx <= 0 && lx >= -0.2 && lz >= 0){
        xx = xx + i+4 * (lx)*0.1;
    }else if(lx <= -0.2 && lx >= -0.4 && lz >= 0){
        zz = zz - i/3 * (lz)*0.1;
        xx = xx + i+2 * (lx)*0.1;
    }else if(lx <= -0.4 && lx >= -0.6 && lz >= 0){
        zz = zz - i/2 * (lz)*0.1;
        xx = xx + i+1 * (lx)*0.1;
    }else if(lx <= -0.6 && lx >= -0.8 && lz >= 0){
        zz = zz + i * (lz)*0.1;
        xx = xx - i/2 * (lx)*0.1;
    }else if(lx <= -0.8 && lx >= -1.0 && lz >= 0){
        zz = zz + i+1 * (lz)*0.1;
    }
    ///////////////////////////
    
    cout<<"XX value is " <<x<<"\n";
    cout<<"LYYY value is " <<ly<<"\n";
    cout<<"LXXX value is " <<lx<<"\n";
    cout<<"LZZZ value is " <<lz<<"\n";
    glLoadIdentity();
    gluLookAt(xx, yy, zz,
            xx + lx, yy + ly, zz + lz,
            0.0f, 1.0f, 0.0f);
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        moveMeAroundLeft(4);
    }
    if(key == 'd' || key == 'D'){
        moveMeAroundRight(4);
//        deltaAngle = 0.01f;
    }
    if(key == 'w' || key =='W'){
        deltaMove = 2;
    }
    
    if(key == 's' || key == 'S'){
        deltaMove = -2;
    }
    if (key == 27)
        exit(0);
}

void processNormalUpKeys(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
         if (deltaAngle < 0.0f)
                deltaAngle = 0.0f;
    }
    
    if(key == 'd' || key == 'D'){
        if (deltaAngle > 0.0f)
                deltaAngle = 0.0f;
    }
    if(key == 'w' || key =='W'){
        if (deltaMove > 0)
                deltaMove = 0;
    }
    
    if(key == 's' || key == 'S'){
         if (deltaMove < 0)
                deltaMove = 0;
    }
    
    if (key == 27)
        exit(0);
}

void RotX(float ang) {
	ly = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(xx, yy, zz, 
			  xx + lx,yy + ly,zz + lz,
			  0,1,0);
}

 void RotY(float ang) {
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(xx, yy, zz, 
			  xx + lx,yy + ly,zz + lz,
			  0.0f,1.0f,0.0f);
}
 
void pressKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT: deltaAngle = -0.01f;
            t += 3.0;
            break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.01f;
            t -= 3.0;
            break;
        case GLUT_KEY_UP: deltaMove = 1;
            break;
        case GLUT_KEY_DOWN: deltaMove = -1;
            break;
           
        case 27:
            exit(0);
            break;
    }

}

void releaseKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT: if (deltaAngle < 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_UP: if (deltaMove > 0)
                deltaMove = 0;
            break;
        case GLUT_KEY_DOWN : if (deltaMove < 0)
                deltaMove = 0;
            break;

    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN)
            glScalef(2.0, 2.0, 2.0);
        else

            cout << "right button lifted at (" << x << "," << y << ")" << endl;
    } else if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN)
            cout << "you shot me" << endl;


    }
}

void motionPassive(int xx, int yy) {
//    glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
//    cout << "Mouse moved at "
//            << "(" << x << "," << y << ")" << endl;
    float angleX = 0;
    angleX = xx / 10 * 0.1f; //- (GLUT_WINDOW_WIDTH)* 0.1f;
//        cout <<"x is "<<x<<"\n";
        RotY(angleX);
        float rotate = 0;
        rotate = x/360;
//        if(x<360){
//            glRotatef(-rotate,0,1,0);
//        }else{
//            glRotatef(rotate,0,1,0);
//        }
        float angleY;
//    if(angle >= 1){
        angleY = yy / 10 * 0.1f; //- (GLUT_WINDOW_HEIGHT)* 0.1f;
//        RotX(angleY);
//    }else if(angle >= 5){
//        angle = y / 10 * -0.1f; //- (GLUT_WINDOW_HEIGHT)* 0.1f;
//        RotX(angle);
//    }

        


}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)

void TimerFunction(int value) {
    yRott += 5;
    glutPostRedisplay();
    glutTimerFunc(3, TimerFunction, 1);
}
