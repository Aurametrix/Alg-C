// Create empty net object
CvConvNet net;

// Load the network from XML representation. 
net.fromString(xmlstring);

// Propagate the image through network
// and get the result
int result = (int) net.fprop(img);

cout << "Image is recognized as " << result << endl;
