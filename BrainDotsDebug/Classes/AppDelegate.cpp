#include "AppDelegate.h"
#include "GLViewUtil.h"
#include "SceneManager.h"
#include "PluginFacebook/PluginFacebook.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    
    sdkbox::PluginFacebook::init();
    
    // initialize path resource
    std::vector<std::string> paths;
    paths.push_back("fonts");
    paths.push_back("data");
    paths.push_back("images");
    paths.push_back("sounds");
    paths.push_back("res");
    paths.push_back("level");
    paths.push_back("particle");
    paths.push_back("shaders");
    paths.push_back("physicseditor");
    paths.push_back("/mnt/sdcard/");
    paths.push_back("internal_dir/");
    paths.push_back(cocos2d::FileUtils::getInstance()->getWritablePath());
    FileUtils::getInstance()->setSearchPaths(paths);
    
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto fitSize = GLViewUtil::calcFitDesignResolutionSize(1334, 750, GLViewUtil::FitType::WIDTH);
    glview->setDesignResolutionSize(fitSize.width, fitSize.height, ResolutionPolicy::SHOW_ALL);
    
    register_all_packages();
    
    auto manageScene = SceneManager::getInstance();
    manageScene->changeState(GAME_STATE::LOGO);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    NotificationCenter::getInstance()->postNotification(PAUSE_GAME);
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
