#define NUM_SPHERES      50
static GLfloat yRott = 0.0f;         // Rotation angle for animation

float angle=0.0,deltaAngle = 0.0,ratio;
float xx=0.0f,yy=0.0f,zz=2.0f,t=0.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
float xRotate = 0,yRotate = 0,zRotate = 0;
float xTranslate = 0,yTranslate = 0,zTranslate = 0;
static GLint DL;

void changeSize(int w1, int h1)
	{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h1 == 0)
		h1 = 1;

	//Very Important: we store w1 and h1 in w , h for next transformations in 
	// SetOrthographicProjection function and others...
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(60,ratio,0.1,1250);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xx, yy, zz, 
		      xx + lx,yy + ly,zz + lz,
			  0.0f,1.0f,0.0f);
	}

void SetupRC() {
	  GLfloat plane[4];
       GLfloat v0[3], v1[3], v2[3];

    // Any three points on the ground (counter clockwise order)
  v0[X] = -30.0f;
  v0[Y] = -149.0f;
  v0[Z] = -20.0f;

  v1[X] = -30.0f;
  v1[Y] = -149.0f;
  v1[Z] = 20.0f;

  v2[X] = 40.0f;
  v2[Y] = -149.0f;
  v2[Z] = 20.0f;

	glEnable(GL_DEPTH_TEST);
//	createDL();
	// Bluish background
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f );
         
    // Draw everything as wire frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat  ambLight[] = { 0.5f, 0.5f, 0.0f, 0.0f };
GLfloat  difLight[] = { 0.5f, 0.5f, 0.0f, 0.0f };
GLfloat  specular[] = { 0.5f, 0.5f, 0.0f, 1.0f};
GLfloat  specref[] =  { 0.5f, 0.5f, 0.0f, 1.0f };





GLfloat fNoLight[] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLfloat fLowLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat fBrightLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat fLightPos[4]   = { -100.0f, 100.0f, 50.0f, 1.0f };


 glClearColor(fLowLight[0], fLowLight[1], fLowLight[2], fLowLight[3]);
         
// Setup Fog parameters
    glEnable(GL_FOG);                   // Turn Fog on
    glFogfv(GL_FOG_COLOR, fLowLight);   // Set fog color to match background
    glFogf(GL_FOG_START, 0.0f);         // How far away does the fog start
    glFogf(GL_FOG_END,80.0f);          // How far away does the fog stop
    glFogi(GL_FOG_MODE, GL_LINEAR);     // Which fog equation do I use?

    // Cull backs of polygons
    //glCullFace(GL_BACK);
    //glFrontFace(GL_CCW);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    
    // Setup light parameters
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fNoLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, fLowLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, fBrightLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, fBrightLight);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
	



// Mostly use material tracking
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMateriali(GL_FRONT, GL_SHININESS, 200);



	// Bluish background
    glClearColor(0.0f, 0.0f, .50f, 1.0f );
         
    // Draw everything as wire frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			// Light values and coordinates

   glEnable(GL_LIGHTING);

	// Setup and enable light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT,   ambLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,difLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);
	
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	//glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	//glMateriali(GL_FRONT,GL_SHININESS,2);
	
   glClearColor(0.0f, 0.5f, 1.0f, 0.5f);
     // Calculate projection matrix to draw shadow on the ground
	findplane(plane, v0, v1, v2);
    shadowmatrix(floorshadow, plane, lightPos);
}

