#ifndef SHA_H_
#define SHA_H_ 
#include <cstddef>
#include <string.h>

typedef unsigned int          uint32_t;
typedef unsigned long long    uint64_t;

uint32_t inline Ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t inline Maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t inline Sigma0(uint32_t x);
uint32_t inline Sigma1(uint32_t x);
uint32_t inline sigma0(uint32_t x);
uint32_t inline sigma1(uint32_t x);
void inline Round(uint32_t a, uint32_t b, uint32_t c, uint32_t& d, uint32_t e, uint32_t f, uint32_t g, uint32_t& h, uint32_t k);
inline uint32_t bswap_32(uint32_t x);
inline uint32_t be32toh(uint32_t big_endian_32bits);
uint32_t inline ReadBE32(const unsigned char* ptr);
void Transform(uint32_t* s, const unsigned char* chunk, size_t blocks);
inline uint64_t bswap_64(uint64_t x);
inline uint64_t htobe64(uint64_t host_64bits);
void inline WriteBE64(unsigned char* ptr, uint64_t x);
inline uint32_t htobe32(uint32_t host_32bits);
void inline WriteBE32(unsigned char* ptr, uint32_t x);

class CSHA256
{
	private:
		//256比特数据
	    uint32_t s[8];
		//64字节数据
	    unsigned char buf[64];
		//64比特数据
	    uint64_t bytes;
	public:
		//结果大小
	    static const int OUTPUT_SIZE = 32;

		//构造函数
	    CSHA256();
		
		/*
			数据进行sha256运算
			data：数据起始地址
			len:要进行哈希的数据长度
		*/
	    CSHA256& Write(const unsigned char *data, size_t len);
		/*
			hash:值结果参数，将本次哈希运算得到的256bit结果
			填入指定的内存区域。
		*/
	    void Finalize(unsigned char hash[OUTPUT_SIZE]);
	    CSHA256& Reset();
};

#endif
