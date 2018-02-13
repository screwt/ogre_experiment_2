
#include "EmptyProjectGameState.h"
#include "DotSceneLoader.h"

#include "CameraController.h"
#include "GraphicsSystem.h"

#include "OgreSceneManager.h"
#include "OgreItem.h"

#include "OgreMeshManager.h"
#include "OgreMeshManager2.h"
#include "OgreMesh2.h"

#include "OgreCamera.h"
#include "OgreRenderWindow.h"

#include "OgreHlmsManager.h"
#include "OgreHlms.h"
#include "Compositor/OgreCompositorWorkspace.h"

#include "OgreHlmsPbs.h"
#include "OgreHlmsPbsDatablock.h"
#include "OgreHlmsSamplerblock.h"

#include "OgreRoot.h"
#include "OgreHlmsManager.h"
#include "OgreHlmsTextureManager.h"
#include "OgreHlmsPbs.h"
#include "OgreLogManager.h"
#include "Compositor/OgreCompositorShadowNode.h"

using namespace Demo;

namespace Demo
{
	EmptyProjectGameState::EmptyProjectGameState( const Ogre::String &helpDescription ) :
	  TutorialGameState( helpDescription ),
	  mSceneNode( 0 )
	{
    }
    //-----------------------------------------------------------------------------------
	void EmptyProjectGameState::createScene01(void)
    {
        mCameraController = new CameraController( mGraphicsSystem, true );

		Ogre::SceneManager *sceneManager = mGraphicsSystem->getSceneManager();	

		DotSceneLoader loader;
		loader.parseDotScene("test.scene","General", sceneManager);
		TutorialGameState::createScene01();
    }
	

    //-----------------------------------------------------------------------------------
	void EmptyProjectGameState::update( float timeSinceLast )
	{
        TutorialGameState::update( timeSinceLast );
    }
    //-----------------------------------------------------------------------------------
	void EmptyProjectGameState::generateDebugText( float timeSinceLast, Ogre::String &outText )
	{
		TutorialGameState::generateDebugText( timeSinceLast, outText );
	}

	void EmptyProjectGameState::switchWorkspace() {
		Ogre::LogManager::getSingleton().logMessage("switchWorkspace");
		mGraphicsSystem->getRoot()->getCompositorManager2();
		mGraphicsSystem->switchWorkSpace();
		//mGraphicsSystem ->getSceneManager()->get
		//Ogre::SceneManager::CameraIterator camNodesIterator = mSceneManager->getCameraIterator();

	}

    //-----------------------------------------------------------------------------------
	void EmptyProjectGameState::keyReleased( const SDL_KeyboardEvent &arg )
    {
		if (arg.keysym.sym == SDLK_c) {
			EmptyProjectGameState::switchWorkspace();
			
		}
		else if ((arg.keysym.mod & ~(KMOD_NUM | KMOD_CAPS)) != 0)
        {
            TutorialGameState::keyReleased( arg );
            return;
        }

		TutorialGameState::keyReleased( arg );
    }
}
