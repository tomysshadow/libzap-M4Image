#ifndef __LIBZAP_H__
#define __LIBZAP_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LIBZAP_API
#define LIBZAP_CALL _cdecl

typedef unsigned char zap_byte_t;
typedef int zap_error_t;
typedef int zap_int_t;
typedef unsigned int zap_uint_t;
typedef size_t zap_size_t;

enum zap_error
{
    ZAP_ERROR_NONE = 0,
    ZAP_ERROR_FILE_FAILED_TO_OPEN,
    ZAP_ERROR_FILE_NOT_FOUND,
    ZAP_ERROR_FILE_ALREADY_EXISTS,
    ZAP_ERROR_READ_ERROR,
    ZAP_ERROR_WRITE_ERROR,
    ZAP_ERROR_INVALID_FILE,
    ZAP_ERROR_INVALID_VERSION,
    ZAP_ERROR_INVALID_FORMAT,
    ZAP_ERROR_INVALID_ARGUMENT,
    ZAP_ERROR_OUT_OF_MEMORY,
    ZAP_ERROR_NOT_IMPLEMENTED,
    ZAP_ERROR_INTERNAL_ERROR
};

enum ZAP_IMAGE_FORMAT
{
    ZAP_IMAGE_FORMAT_PNG = 0,
    ZAP_IMAGE_FORMAT_JPG = 1,
    ZAP_IMAGE_FORMAT_JTIF = 2
};

enum ZAP_COLOR_FORMAT
{
    ZAP_COLOR_FORMAT_RGBA32 = 0,
};

/// Load a ZAP file from disk
/// \param filename The path to the ZAP file
/// \param colorFormat The color format of the image
/// \param pOut A pointer to the output data
/// \param pOutSize A pointer to the output data size
/// \param pOutWidth A pointer to the output image width
/// \param pOutHeight A pointer to the output image height
/// \return 0 on success, non-zero on failure
LIBZAP_API zap_error_t LIBZAP_CALL zap_load(const char* filename, zap_uint_t colorFormat, zap_byte_t** pOut, zap_size_t* pOutSize, const zap_int_t* pOutWidth, const zap_int_t* pOutHeight);

/// Load a ZAP file from memory
/// \param pData The data to load
/// \param colorFormat The color format of the image
/// \param pOut A pointer to the output data
/// \param pOutSize A pointer to the output data size
/// \param pOutWidth A pointer to the output image width
/// \param pOutHeight A pointer to the output image height
/// \return 0 on success, non-zero on failure
LIBZAP_API zap_error_t LIBZAP_CALL zap_load_memory(const unsigned char* pData, zap_uint_t colorFormat, zap_byte_t** pOut, zap_size_t* pOutSize, zap_int_t* pOutWidth, zap_int_t* pOutHeight);

/// Free the data loaded by zap_load or zap_load_memory
/// \param pData The data to free
/// \return 0 on success, non-zero on failure
LIBZAP_API zap_error_t LIBZAP_CALL zap_free(const zap_byte_t* pData);

/// Save a ZAP file to disk
/// \param filename The path to save the ZAP file to
/// \param pData The data to save
/// \param dataSize The size of the data to save
/// \param width The width of the image
/// \param height The height of the image
/// \param colorFormat The color format of the image
/// \param format The format of the image
/// \return 0 on success, non-zero on failure
LIBZAP_API zap_error_t LIBZAP_CALL zap_save(const char* filename, const zap_byte_t* pData, zap_size_t dataSize, zap_int_t width, zap_int_t height, zap_uint_t colorFormat, zap_uint_t format);

/// Save a ZAP file to memory
/// \param pOut A pointer to the output data
/// \param pOutSize A pointer to the output data size
/// \param width The width of the image
/// \param height The height of the image
/// \param colorFormat The color format of the image
/// \param format The format of the image
/// \return 0 on success, non-zero on failure
LIBZAP_API zap_error_t LIBZAP_CALL zap_save_memory(zap_byte_t** pOut, zap_size_t* pOutSize, zap_int_t width, zap_int_t height, zap_uint_t colorFormat, zap_uint_t format);

#ifdef __cplusplus
}
#endif

#endif // __LIBZAP_H__