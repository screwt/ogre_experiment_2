
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
        mCameraController = new CameraController( mGraphicsSystem, false );

	Ogre::SceneManager *sceneManager = mGraphicsSystem->getSceneManager();
        
	/*
        Ogre::Item *item = sceneManager->createItem( "Cube_d.mesh",
                                                     Ogre::ResourceGroupManager::
                                                     AUTODETECT_RESOURCE_GROUP_NAME,
                                                     Ogre::SCENE_DYNAMIC );	
        mSceneNode = sceneManager->getRootSceneNode( Ogre::SCENE_DYNAMIC )->
                createChildSceneNode( Ogre::SCENE_DYNAMIC );
        mSceneNode->attachObject( item );
	*/
	
	//sceneManager->setForwardClustered( true, 16, 8, 24, 96, 5, 500 );

	

	DotSceneLoader loader;
	loader.parseDotScene("test.scene","General", sceneManager);


	/*
	Ogre::Item *item2 = sceneManager->createItem( "Cube_d.mesh",
						     Ogre::ResourceGroupManager::
						     AUTODETECT_RESOURCE_GROUP_NAME,
						     Ogre::SCENE_DYNAMIC );
	Ogre::Item *item3 = sceneManager->createItem( "Cube_d.mesh",
						     Ogre::ResourceGroupManager::
						     AUTODETECT_RESOURCE_GROUP_NAME,
						     Ogre::SCENE_DYNAMIC );	
	Ogre::SceneNode *mSceneNode = sceneManager->getRootSceneNode( Ogre::SCENE_DYNAMIC )->
	  createChildSceneNode( Ogre::SCENE_DYNAMIC );
	Ogre::SceneNode *mSceneNode2 = sceneManager->getRootSceneNode( Ogre::SCENE_DYNAMIC )->
	  createChildSceneNode( Ogre::SCENE_DYNAMIC );	
	mSceneNode->attachObject( item2 );	
	mSceneNode2->attachObject( item3 );
	mSceneNode->setPosition( 3, 3, 3 );
	mSceneNode2->setPosition( 4, 2, 4 );
	*/
	/*
	Ogre::Hlms *hlms = mGraphicsSystem->getRoot()->getHlmsManager()->getHlms( Ogre::HLMS_PBS );     
        assert( dynamic_cast<Ogre::HlmsPbs*>( hlms ) );
        Ogre::HlmsPbs *pbs = static_cast<Ogre::HlmsPbs*>( hlms );
        pbs->setShadowSettings( Ogre::HlmsPbs::NumShadowFilter  );
	*/



	/*
        Ogre::v1::MeshPtr planeMeshV1 = Ogre::v1::MeshManager::getSingleton().createPlane( "Plane v1",
                                            Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
                                            Ogre::Plane( Ogre::Vector3::UNIT_Y, 1.0f ), 5000.0f, 5000.0f,
                                            1, 1, true, 1, 4.0f, 4.0f, Ogre::Vector3::UNIT_Z,
                                            Ogre::v1::HardwareBuffer::HBU_STATIC,
                                            Ogre::v1::HardwareBuffer::HBU_STATIC );

        Ogre::MeshPtr planeMesh = Ogre::MeshManager::getSingleton().createManual(
                    "Plane", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME );

        planeMesh->importV1( planeMeshV1.get(), true, true, true );

        {
            Ogre::Item *item = sceneManager->createItem( planeMesh, Ogre::SCENE_DYNAMIC );
            Ogre::SceneNode *sceneNode = sceneManager->getRootSceneNode( Ogre::SCENE_DYNAMIC )->
                                                    createChildSceneNode( Ogre::SCENE_DYNAMIC );
            sceneNode->setPosition( 0, -1, 0 );
            sceneNode->attachObject( item );
        }
	


	
	Ogre::Light *light = sceneManager->createLight();
        Ogre::SceneNode *lightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
        lightNode->attachObject( light );
        light->setPowerScale( 3 ); //Since we don't do HDR, counter the PBS' division by PI
        light->setType( Ogre::Light::LT_DIRECTIONAL);
	//light->setType( Ogre::Light::LT_POINT);
	light->setDiffuseColour(1, 1, 1);
	light->setSpecularColour(1, 1, 1);
        //light->setDirection( Ogre::Vector3( -1, -1, -1 ).normalisedCopy() );
	//lightNode->setPosition(Ogre::Vector3( 300, 300, 300 ));
	lightNode->setPosition( 10.0f, 10.0f, -10.0f );
        light->setDirection( Ogre::Vector3( -1, -1, 1 ).normalisedCopy() );
        light->setAttenuationBasedOnRadius( 100.0f, 0.001f );
	
	
	*/
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
    //-----------------------------------------------------------------------------------
	void EmptyProjectGameState::keyReleased( const SDL_KeyboardEvent &arg )
    {
        if( (arg.keysym.mod & ~(KMOD_NUM|KMOD_CAPS)) != 0 )
        {
            TutorialGameState::keyReleased( arg );
            return;
        }

		TutorialGameState::keyReleased( arg );
    }
}
