#ifndef HND_DEPTH_UTILITY_H
#define HND_DEPTH_UTILITY_H

#include <opencv2/imgproc/imgproc.hpp>
#include <AstraUL/AstraUL.h>
#include "hnd_settings.hpp"
#include <cstdint>

namespace astra { namespace hand {

    class depth_utility
    {
    public:
        depth_utility(float width, float height, depth_utility_settings& settings);
        virtual ~depth_utility();

        void depth_to_velocity_signal(DepthFrame& depthFrame,
                                      cv::Mat& matDepth,
                                      cv::Mat& matDepthFullSize,
                                      cv::Mat& matVelocitySignal);
        void reset();

        const cv::Mat& matDepthVel() const { return matDepthVel_; }
        const cv::Mat& matDepthAvg() const { return matDepthAvg_; }
        const cv::Mat& matDepthVelErode() const { return matDepthVelErode_; }
        const cv::Mat& matDepthFilled() const { return matDepthFilled_; }

    private:
        enum class fill_mask_type : std::uint8_t
        {
            normal = 0,
            filled = 1
        };

        static void depthframe_to_matrix(DepthFrame& depthFrameSrc,
                                         const int width,
                                         const int height,
                                         cv::Mat& matTarget);

        static void fill_zero_values(cv::Mat& matDepth,
                                     cv::Mat& matDepthFilled,
                                     cv::Mat& matDepthFilledMask,
                                     cv::Mat& matDepthPrevious);

        static void filter_zero_values_and_jumps(cv::Mat& depthCurrent,
                                                 cv::Mat& depthPrev,
                                                 cv::Mat& depthAvg,
                                                 cv::Mat& matDepthFilledMask,
                                                 const float maxDepthJumpPercent);
        void threshold_velocity_signal(cv::Mat& matVelocityFiltered,
                                       cv::Mat& matVelocitySignal,
                                       const float velocityThresholdFactor);

        void adjust_velocities_for_depth(cv::Mat& matDepth,
                                         cv::Mat& matVelocityFiltered);

        int depth_to_chunk_index(float depth);

        void analyze_velocities(cv::Mat& matDepth,
                                cv::Mat& matVelocityFiltered);

        const float processingWidth_;
        const float processingHeight_;

        cv::Mat rectElement_;
        cv::Mat rectElement2_;
        cv::Mat matDepthOriginal_;
        cv::Mat matDepthPrevious_;
        cv::Mat matDepthFilled_;
        cv::Mat matDepthFilledMask_;
        cv::Mat matDepthAvg_;
        cv::Mat matDepthVel_;
        cv::Mat matDepthVelErode_;

        float depthSmoothingFactor_;
        float velocityThresholdFactor_;
        float maxDepthJumpPercent_;
        int erodeSize_;
        float depthAdjustmentFactor_;
        float minDepth_;
        float maxDepth_;

        static const int NUM_DEPTH_VEL_CHUNKS = 8;
        const float MIN_CHUNK_DEPTH = 0.0f;
        const float MAX_CHUNK_DEPTH = 8000.0f;
        float velErodeFactor_{ 0.98f };
        float maxVel_[NUM_DEPTH_VEL_CHUNKS];
        float depthCount_[NUM_DEPTH_VEL_CHUNKS];
    };
}}

#endif // HND_DEPTH_UTILITY_H