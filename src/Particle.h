#pragma once
#include "ofMain.h"

enum particleMode{
	PARTICLE_MODE_ATTRACT = 0,
	PARTICLE_MODE_REPEL,
	PARTICLE_MODE_NEAREST_POINTS,
	PARTICLE_MODE_NOISE,
	PARTICLE_MODE_PAUSE,
	NONE
};

class Particle{

	public:
		Particle();
		
		void setMode(particleMode newMode);	
		void setModeBeforePause(particleMode mode);
		void setAttractPoints( vector <glm::vec3> * attract );
		void attractToPoint(int, int);
		void repelFromPoint(int, int);
		void reset();
		void update();
		void draw();
		void changeParticleColor(int);
		void magnifyParticle(bool dragRectangle, int originalMouseX, int newMouseX, int originalMouseY, int newMouseY);
		
		glm::vec3 pos;
		glm::vec3 vel;
		glm::vec3 frc;
		
		float drag; 
		float uniqueVal;
		float scale;
		
		particleMode mode;
		particleMode lastMode;
		
		vector <glm::vec3> * attractPoints; 
};
