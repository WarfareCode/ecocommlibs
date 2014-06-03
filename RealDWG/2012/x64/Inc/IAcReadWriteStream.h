// $Header: //depot/release/ironman2012/develop/global/inc/dbxsdk/IAcReadWriteStream.h#1 $
// $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
//
//  Copyright 2008-2009 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//
//  DESCRIPTION: IAcReadStream and IAcWriteStream general purpose
//  filing interfaces

#pragma once

/// <summary>
/// Interface for a readable stream.
/// </summary>
class __declspec(novtable) IAcReadStream
{
  public:
    /// <summary>
    /// return codes
    /// </summary>
    enum {
            /// <summary>
            /// No errors occurred
            /// </summary>
            eOk = 0,
            /// <summary>
            /// This function is not supported for this stream object
            /// </summary>
            eNotSupported = 1,
            /// <summary>
            /// The stream is not open
            /// </summary>
            eNotOpen = 2,
            /// <summary>
            /// One of the arguments is an invalid value
            /// </summary>
            eInvalidArg = 3,
            /// <summary>
            /// The stream is at the end of the file
            /// </summary>
            eEndOfFile = 4,
            /// <summary>
            /// The disk to which the stream is writing is full
            /// </summary>
            eDiskFull = 5,
            /// <summary>
            /// The stream is disconnected
            /// </summary>
            eDisconnected = 6,
            /// <summary>
            /// Unknown error
            /// </summary>
            eJustAnError = 7
    };

    /// <summary>
    /// seek mode arguments
    /// </summary>
    enum {
            /// <summary>
            /// Seek from start of stream
            /// </summary>
            eFromStart = 0,
            /// <summary>
            /// Seek from current stream position
            /// </summary>
            eFromCurrent = 1,
            /// <summary>
            /// Seek from end of stream
            /// </summary>
            eFromEnd = 2
    };

    /// <summary>
    /// This function sets the stream position to be nDistance from the nMode stream
    /// location.  If nDistance is negative, then the new position will be that distance
    /// earlier in the stream, otherwise it will be nDistance after the nMode location.
    /// </summary>
    /// <param name="nDistance">Input distance to seek from nMode position</param>
    /// <param name="nMode">Input seek mode</param>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the seek operation.</returns>
    virtual int  seek(__int64 nDistance, int nMode) { return eNotSupported; }

    /// <summary>
    /// This function sets nOffset to the current stream position relative to the start of the stream.
    /// </summary>
    /// <returns>Returns the distance from the start of the stream to the current read/write position.  Returns -1 by default.</returns>
    virtual __int64 tell() { return -1; }

    /// <summary>
    /// This function reads nNumBytes bytes of data from the stream and copies it into the location
    /// pointed to by pDestBuf.  The value pointed to by pNumRead is set to the number of bytes
    /// actually read and copied to pDestBuf.
    /// Some implementations may return eOk when the number of bytes read is less than
    /// the number requested.  Others may return eEndOfFile in that case.
    /// </summary>
    /// NOTE: when implementing a class derived from IAcReadStream, the read() method must be
    /// overridden, but all other IAcReadStream methods can be the default implementations.
    /// <param name="pDestBuf">Input pointer to location to copy stream data to</param>
    /// <param name="nNumBytes">Input number of bytes to read from stream</param>
    /// <param name="pNumRead">Output number of bytes read from stream</param>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the read operation.</returns>
    virtual int read(void* pDestBuf, size_t nNumBytes,
                                     size_t *pNumRead) = 0;

    /// <summary>
    /// This function closes the stream, and may also deallocate the stream object.
    /// </summary>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the close operation.</returns>
    virtual int  close() { return eNotSupported; }

    /// <summary>
    /// Auxiliary method for implementation-specific functionality.
    /// </summary>
    /// <param name="nArg">Input value, implementation dependent</param>
    /// <returns>An implementation dependent value.</returns>
    virtual __int64 control(__int64 nArg) { return 0; }

  protected:
    /// <summary>
    /// Destructor
    /// </summary>
    virtual ~IAcReadStream() {}     // no explicit deletes
};

/// <summary>
/// Interface for a read/write stream.
/// </summary>
class __declspec(novtable) IAcWriteStream : public IAcReadStream
{
  public:
    /// <summary>
    /// This function copies nNumBytes bytes of data from the location pointed to by pSrcBuf to the
    /// stream.  The value pointed to by pNumWritten is set to the number of bytes actually copied
    /// to the stream.
    /// </summary>
    /// NOTE: When implementing a class derived from IAcWriteStream, the write() method must be
    /// overridden, but all other IAcWriteStream methods can be the default implementations.
    /// <param name="pSrcBuf">Input pointer to location of data to be written to the stream</param>
    /// <param name="nNumBytes">Input number of bytes to write to the stream</param>
    /// <param name="pNumWritten">Output number of bytes written to the stream</param>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the write operation.</returns>
    virtual int write(const void* pSrcBuf, size_t nNumBytes,
                      size_t *pNumWritten) = 0;

    /// <summary>
    /// This function flushes any buffers used by the stream.
    /// </summary>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the operation.</returns>
    virtual int flushBuffers() { return eNotSupported; }

    /// <summary>
    /// This function sets the current stream position as the end of file.
    /// </summary>
    /// <returns>Returns a status (such as eOk) indicating the outcome of the operation.</returns>
    virtual int setEndOfFile() { return eNotSupported; }
  protected:
    /// <summary>
    /// Destructor
    /// </summary>
    virtual ~IAcWriteStream() {} // no explicit deletes
};

