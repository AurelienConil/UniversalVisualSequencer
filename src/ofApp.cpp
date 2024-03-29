#include "ofApp.h"
#define PORT 12345



//--------------------------------------------------------------
void ofApp::setup()
{

    listOfVisual.clear();
    ofSetVerticalSync(true);
    
    //setup osc receiver
    receiver.setup(PORT);
    
}

//--------------------------------------------------------------
void ofApp::update()
{

    for (vector<shared_ptr<VisualScene>>::iterator itn = listOfVisual.begin(); itn < listOfVisual.end();)
    {

        itn->get()->update();

        // SCENE IS OVER
        if (itn->get()->currentState == VisualScene::DIE)
        {
            // Kill the visual
            // delete itn->get();
            itn = listOfVisual.erase(itn);
        }
        else
        {
            // Weird but true
            ++itn;
        }
    }
    
    //handle reception of osc messages
    while(receiver.hasWaitingMessages()){
        //get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        //check for mouse moved message
        if(m.getAddress() == "/basic/rotatingsquare"){
            //both the arguments are int32's
            int p1 = m.getArgAsInt32(0);
            int p2 = m.getArgAsInt32(1);
            
            listOfVisual.push_back(make_shared<RotatingSquare>(p1, p2, 0, 0, 0, 0, 0, 0));
            
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{

    for (auto visual : listOfVisual)
    {
        visual->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    switch (key)
    {
    case 'a':
        listOfVisual.push_back(make_shared<VibratingCircle>(ofRandom(100), ofRandom(200), ofRandom(80, 200), 0, 0, 0, 0, 0));
        break;
    case 'b':
        listOfVisual.push_back(make_shared<RotatingSquare>(ofRandom(100), ofRandom(127), 0, 0, 0, 0, 0, 0));
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
