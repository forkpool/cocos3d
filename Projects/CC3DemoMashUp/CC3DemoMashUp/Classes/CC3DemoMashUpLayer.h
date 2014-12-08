/*
 * CC3DemoMashUpLayer.h
 *
 * Cocos3D 2.0.2
 * Author: Bill Hollings
 * Copyright (c) 2010-2014 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * http://en.wikipedia.org/wiki/MIT_License
 */


#import "CC3Layer.h"
#import "Joystick.h"
#import "CCNodeAdornments.h"

// In Cocos2D v1 & v2, buttons are actually menu items
#if CC3_CC2_CLASSIC
#	define CC_BUTTON_CLASS		AdornableMenuItemImage
#else
#	define CC_BUTTON_CLASS		AdornableButton
#endif	// CC3_CC2_CLASSIC

/**
 * A sample application-specific CC3Layer subclass that allows the user to interact with
 * the 3D scene using either gestures or overlay controls such as joysticks and buttons.
 * 
 * Under iOS, by default, this layer uses gestures to interact with the 3D nodes. You can 
 * turn gestures off by setting the touchEnabled property to YES in the initializeControls
 * method of this class. Gesture support under Android is less sophisticated, so by default,
 * gestures are turned off when running under Android.
 *
 * With touchEnabled set to YES, gestures are turned off, and this layer and scene revert to
 * using basic touch events to interact with the 3D scene. Normally, you would use one or the
 * other technique. Both are provided in this app to demonstrate user interaction using either
 * gestures or touch events.
 */
@interface CC3DemoMashUpLayer : CC3Layer {
	Joystick* _directionJoystick;
	Joystick* _locationJoystick;
	CC_BUTTON_CLASS* _switchViewButton;
	CC_BUTTON_CLASS* _invasionButton;
	CC_BUTTON_CLASS* _sunlightButton;
	CC_BUTTON_CLASS* _zoomButton;
	CC_BUTTON_CLASS* _shadowButton;
	CC3Layer* _hudLayer;
}

/**
 * Opens a secondary heads-up-display CC3Layer that holds a CC3Scene that
 * contains only the globe. The opening of this secondary layer is animated.
 */
-(void) openGlobeHUDFromTouchAt: (CGPoint) touchPoint;

/** Closes the secondary HUD layer. The closing is animated. */
-(void) closeGlobeHUDFromTouchAt: (CGPoint) touchPoint;

/**
 * If the HUD window is not open, opens it by invoking the openGlobeHUDFromTouchAt:
 * method. If the HUD window is already open, closes it by invoking the
 * closeGlobeHUDFromTouchAt: method.
 *
 * This is invoked from a touch-handing event when the globe is touched.
 */
-(void) toggleGlobeHUDFromTouchAt: (CGPoint) touchPoint;

/**
 * Removes the secondary HUD window from this layer once it has closed.
 *
 * This is invoked automatically from the CCAction that animates the closing of the HUD window.
 */
-(void) removeGlobeHUD;

@end
