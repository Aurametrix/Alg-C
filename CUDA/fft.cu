FFT::StatusType FFT::computeBackwardBatched(ComplexTypePtr src, RealTypePtr dst)
    {
        StatusType s = cufftExecC2R(backward_handle_, reinterpret_cast<cufftComplex*>(src), dst);
        dim3 gridSize((getBatchSize() * getForwardDataSize()) / thr_max_ + 1, 1, 1);
        dim3 blockSize(thr_max_, 1, 1);
        float val = getForwardDataSize();
        kernelDivide <<< gridSize, blockSize >>> (dst, val, getBatchSize() * getForwardDataSize());
        return s;
    }

    FFT::StatusType FFT::computeBackwardBatched(ComplexVector& src, Vector& dst)
    {
        return computeBackwardBatched(src.getData(), dst.getData());
    }
