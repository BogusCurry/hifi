//
//  VoxelPacketData.h
//  hifi
//
//  Created by Brad Hefta-Gaub on 11/19/2013
//
//  TO DO:
//
//    *  add stats tracking for number of unique colors and consecutive identical colors.
//          (as research for color dictionaries and RLE)
//
//    *  further testing of compression to determine optimal configuration for performance and compression
//
//    *  improve semantics for "reshuffle" - current approach will work for now and with compression
//       but wouldn't work with RLE because the colors in the levels would get reordered and RLE would need
//       to be recalculated
//

#ifndef __hifi__VoxelPacketData__
#define __hifi__VoxelPacketData__

#include <SharedUtil.h>

#include <OctreePacketData.h>

#include "VoxelConstants.h"
#include "VoxelTreeElement.h"

typedef unsigned char VOXEL_PACKET_FLAGS;
typedef uint16_t VOXEL_PACKET_SEQUENCE;
typedef quint64 VOXEL_PACKET_SENT_TIME;
typedef uint16_t VOXEL_PACKET_INTERNAL_SECTION_SIZE;
const int MAX_VOXEL_PACKET_SIZE = MAX_PACKET_SIZE;

// this is overly conservative - uses 8 bytes for PacketType which could be as compact as a single byte
const int VOXEL_PACKET_HEADER_SIZE = MAX_PACKET_HEADER_BYTES + sizeof(VOXEL_PACKET_FLAGS)
                + sizeof(VOXEL_PACKET_SEQUENCE) + sizeof(VOXEL_PACKET_SENT_TIME);

const int MAX_VOXEL_PACKET_DATA_SIZE = MAX_PACKET_SIZE - VOXEL_PACKET_HEADER_SIZE;
            
const int MAX_VOXEL_UNCOMRESSED_PACKET_SIZE = MAX_VOXEL_PACKET_DATA_SIZE;

/// Handles packing of the data portion of PacketType_VOXEL_DATA messages.
class VoxelPacketData : public OctreePacketData {
public:
    VoxelPacketData(bool enableCompression = false, int maxFinalizedSize = MAX_OCTREE_PACKET_DATA_SIZE);
};

#endif /* defined(__hifi__VoxelPacketData__) */