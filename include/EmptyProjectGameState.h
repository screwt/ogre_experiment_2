
#ifndef _Demo_EmptyProjectGameState_H_
#define _Demo_EmptyProjectGameState_H_

#include "OgrePrerequisites.h"
#include "TutorialGameState.h"
#include "DotSceneLoader.h"
namespace Demo
{
  struct GameEntity;
  struct MovableObjectDefinition;

  
	class EmptyProjectGameState : public TutorialGameState
    {
        virtual void generateDebugText( float timeSinceLast, Ogre::String &outText );
	
		Ogre::Root      *mRoot;
		Ogre::SceneNode *mSceneNode;	
		DotSceneLoader *mLoader;
		std::vector<Ogre::CompositorWorkspace*> mCompositorWorkspaces;
		std::vector<Ogre::CompositorWorkspace*>::iterator mActiveWorkspace;

		public:
		EmptyProjectGameState( const Ogre::String &helpDescription );
		void setupAfterSceneLoaded(void);
        virtual void createScene01(void);

        virtual void update( float timeSinceLast );

        virtual void keyReleased( const SDL_KeyboardEvent &arg );

		void switchWorkspace();
		
    };
}

#endif
