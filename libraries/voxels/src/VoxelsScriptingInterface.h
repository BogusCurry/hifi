//
//  VoxelsScriptingInterface.h
//  hifi
//
//  Created by Stephen Birarda on 9/17/13.
//  Copyright (c) 2013 HighFidelity, Inc. All rights reserved.
//

#ifndef __hifi__VoxelsScriptingInterface__
#define __hifi__VoxelsScriptingInterface__

#include <QtCore/QObject>

#include <OctreeScriptingInterface.h>

#include "VoxelConstants.h"
#include "VoxelEditPacketSender.h"

/// handles scripting of voxel commands from JS passed to assigned clients
class VoxelsScriptingInterface : public OctreeScriptingInterface {
    Q_OBJECT
public:    
    VoxelEditPacketSender* getVoxelPacketSender() { return (VoxelEditPacketSender*)getPacketSender(); }

    virtual NodeType_t getServerNodeType() const { return NodeType::VoxelServer; }
    virtual OctreeEditPacketSender* createPacketSender() { return new VoxelEditPacketSender(); }

public slots:
    /// queues the creation of a voxel which will be sent by calling process on the PacketSender
    /// \param x the x-coordinate of the voxel (in meter units)
    /// \param y the y-coordinate of the voxel (in meter units)
    /// \param z the z-coordinate of the voxel (in meter units)
    /// \param scale the scale of the voxel (in meter units)
    /// \param red the R value for RGB color of voxel
    /// \param green the G value for RGB color of voxel
    /// \param blue the B value for RGB color of voxel
    void setVoxelNonDestructive(float x, float y, float z, float scale, uchar red, uchar green, uchar blue);

    /// queues the destructive creation of a voxel which will be sent by calling process on the PacketSender
    /// \param x the x-coordinate of the voxel (in meter units)
    /// \param y the y-coordinate of the voxel (in meter units)
    /// \param z the z-coordinate of the voxel (in meter units)
    /// \param scale the scale of the voxel (in meter units)
    /// \param red the R value for RGB color of voxel
    /// \param green the G value for RGB color of voxel
    /// \param blue the B value for RGB color of voxel
    void setVoxel(float x, float y, float z, float scale, uchar red, uchar green, uchar blue);

    /// queues the deletion of a voxel, sent by calling process on the PacketSender
    /// \param x the x-coordinate of the voxel (in meter units)
    /// \param y the y-coordinate of the voxel (in meter units)
    /// \param z the z-coordinate of the voxel (in meter units)
    /// \param scale the scale of the voxel (in meter units)
    void eraseVoxel(float x, float y, float z, float scale);

private:
    void queueVoxelAdd(PacketType addPacketType, VoxelDetail& addVoxelDetails);
};

#endif /* defined(__hifi__VoxelsScriptingInterface__) */
