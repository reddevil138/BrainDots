LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path, $(LOCAL_PATH))

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/SoundManager/SoundManager.cpp \
                   ../../Classes/MenuScene/BasePopupLayer.cpp \
                   ../../Classes/MenuScene/MenuPopupLayer.cpp \
                   ../../Classes/MenuScene/PencilPopupLayer.cpp \
                   ../../Classes/MenuScene/RecordPopupLayer.cpp \
                   ../../Classes/MenuScene/SharePopupLayer.cpp \
                   ../../Classes/MenuScene/MenuScene.cpp \
                   ../../Classes/BallContactListener.cpp \
                   ../../Classes/GLESDebugDraw.cpp \
                   ../../Classes/TiledBodyCreator.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/LogoScene.cpp \
                   ../../Classes/SceneManager.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END