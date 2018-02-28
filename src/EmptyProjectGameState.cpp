
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

#include "Compositor/OgreCompositorManager2.h"
#include "Compositor/OgreCompositorWorkspace.h"

using namespace Demo;

namespace Demo
{
  EmptyProjectGameState::EmptyProjectGameState( const Ogre::String &helpDescription ) :
    TutorialGameState( helpDescription ),
    mSceneNode( 0 )
  {}

  //-----------------------------------------------------------------------------------
  void EmptyProjectGameState::createScene01(void)
  {
    mCameraController = new CameraController( mGraphicsSystem, false );
    Ogre::SceneManager *sceneManager = mGraphicsSystem->getSceneManager();	
    mLoader = new DotSceneLoader();
    mLoader->parseDotScene("test.scene", "General", sceneManager);
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

  void EmptyProjectGameState::setupAfterSceneLoaded(void) {
    Ogre::LogManager::getSingleton().logMessage("-- setupAfterSceneLoaded");
    //Ogre::SceneManager::CameraIterator camNodesIterator = mGraphicsSystem->getSceneManager()->getCameraIterator();
    Ogre::CompositorManager2 *compositorManager = mGraphicsSystem->getRoot()->getCompositorManager2();
    mCompositorWorkspaces.push_back(mGraphicsSystem->getCompositorWorkspace());
    //Ogre::SceneManager::CameraList cml = mSceneManager->getCameras();
    
    for (std::vector<Ogre::Camera*>::iterator camerasNodesIt = mLoader->camerasNodes.begin();
         camerasNodesIt != mLoader->camerasNodes.end(); camerasNodesIt++) {
      Ogre::Camera* cam = *camerasNodesIt;
      Ogre::LogManager::getSingleton().logMessage("-- loaded cam");
      Ogre::LogManager::getSingleton().logMessage("Loaded CAMERA " + cam->getName());
      Ogre::CompositorWorkspace* cw = compositorManager->addWorkspace(
                                                                      mGraphicsSystem->getSceneManager(),
                                                                      mGraphicsSystem->getRenderWindow(),
                                                                      cam,
                                                                      "EmptyProjectWorkspace", false);
      mCompositorWorkspaces.push_back(cw);
      
    }

    mActiveWorkspace = mCompositorWorkspaces.begin();
    Ogre::LogManager::getSingleton().logMessage("-- set ws");
    Ogre::CompositorWorkspace* ws = *mActiveWorkspace;
    Ogre::LogManager::getSingleton().logMessage("-- set ws done");
    ws->setEnabled(true);
  }

  void EmptyProjectGameState::switchWorkspace() {
    Ogre::CompositorWorkspace* ws = *mActiveWorkspace;
    ws->setEnabled(false);
    mActiveWorkspace++;
    if (mActiveWorkspace == mCompositorWorkspaces.end())
      mActiveWorkspace = mCompositorWorkspaces.begin();
       
    ws = *mActiveWorkspace;
    ws->setEnabled(true);
    mGraphicsSystem->setCamera(ws->getDefaultCamera());
    Ogre::LogManager::getSingleton().logMessage("switchWorkspace camName:"+ws->getDefaultCamera()->getName());
    Ogre::Quaternion q = ws->getDefaultCamera()->getOrientation();
    std::ostringstream ostr;
    ostr << "    orientation:" << q.w <<  "/" << q.x << "/" << q.y << "/" << q.z;
    q = ws->getDefaultCamera()->getParentNode()->getOrientation();
    ostr << "\n    Parent orientation:" << q.w <<  "/" << q.x << "/" << q.y << "/" << q.z;
    Ogre::LogManager::getSingleton()
      .logMessage(ostr.str() );
  }
  

  void EmptyProjectGameState::switchScene() {
    Ogre::LogManager::getSingleton().logMessage("switchScene");
  }

  //-----------------------------------------------------------------------------------
  void EmptyProjectGameState::keyReleased( const SDL_KeyboardEvent &arg )
  {
    if (arg.keysym.sym == SDLK_c) {
      EmptyProjectGameState::switchWorkspace();  
    }else if (arg.keysym.sym == SDLK_n){
      EmptyProjectGameState::switchScene();
    }else if ((arg.keysym.mod & ~(KMOD_NUM | KMOD_CAPS)) != 0){
      TutorialGameState::keyReleased( arg );
      return;
    }

    TutorialGameState::keyReleased( arg );
  }
}
