#ifndef TRACKEDPOINT_H
#define TRACKEDPOINT_H

#include <opencv2/core/affine.hpp>
#include "TrackingData.h"

namespace astra { namespace plugins { namespace hand {

    struct TrackedPoint
    {
    public:
        cv::Point position;
        cv::Point3f worldPosition;
        cv::Point3f worldDeltaPosition;
        cv::Point fullSizePosition;
        cv::Point3f fullSizeWorldPosition;
        cv::Point3f fullSizeWorldDeltaPosition;
        cv::Point3f steadyWorldPosition;
        int trackingId;
        int inactiveFrameCount;
        int failedTestCount;
        bool isInProbation;
        int probationFrameCount;
        TrackedPointType pointType;
        TrackingStatus trackingStatus;
        float referenceAreaSqrt;

        TrackedPoint(cv::Point position, cv::Point3f worldPosition, int trackingId) :
            position(position),
            worldPosition(worldPosition),
            worldDeltaPosition(),
            fullSizePosition(),
            fullSizeWorldPosition(),
            fullSizeWorldDeltaPosition(),
            steadyWorldPosition(worldPosition),
            trackingId(trackingId),
            inactiveFrameCount(0),
            failedTestCount(0),
            isInProbation(true),
            probationFrameCount(0),
            pointType(TrackedPointType::CandidatePoint),
            trackingStatus(TrackingStatus::NotTracking),
            referenceAreaSqrt(0)
        { }
    };
}}}

#endif // TRACKEDPOINT_H
