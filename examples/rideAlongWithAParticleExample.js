//
//  rideAlongWithAParticleExample.js
//  hifi
//
//  Created by Brad Hefta-Gaub on 1/24/14.
//  Copyright (c) 2014 HighFidelity, Inc. All rights reserved.
//
//  This is an example script that demonstrates "finding" particles
//

var iteration = 0;
var lengthOfRide = 2000; // in iterations

var particleA = Particles.addParticle(
                    {
                        position: { x: 10, y: 0, z: 10 },
                        velocity: { x: 5, y: 0, z: 5 },
                        gravity: { x: 0, y: 0, z: 0 },
                        radius : 0.1,
                        color: { red: 0, green: 255, blue: 0 },
                        damping: 0,
                        lifetime: (lengthOfRide * 60) + 1
                    });

function rideWithParticle() {

    if (iteration <= lengthOfRide) {

        // Check to see if we've been notified of the actual identity of the particles we created
        if (!particleA.isKnownID) {
            particleA = Particles.identifyParticle(particleA);
        }

        var propertiesA = Particles.getParticleProperties(particleA);
        var newPosition = propertiesA.position;
        MyAvatar.position = { x: propertiesA.position.x, 
                              y: propertiesA.position.y + 2,
                              z: propertiesA.position.z  };
    } else {
        Script.stop();
    }
                              
    iteration++;
    print("iteration="+iteration);
}


// register the call back so it fires before each data send
Script.willSendVisualDataCallback.connect(rideWithParticle);

