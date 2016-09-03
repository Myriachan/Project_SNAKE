#pragma once
#include <vector>
#include "types.h"
#include "ByteBuffer.h"
#include "es_crypto.h"
#include "es_cert.h"

class EsCertChain
{
public:
	EsCertChain();
	~EsCertChain();

	const EsCert& operator[](size_t index) const;
	const EsCert& operator[](const std::string& signer) const;

	// Export serialised data
	const u8* GetSerialisedData() const;
	size_t GetSerialisedDataSize() const;

	// serialise chain
	void SerialiseCertChain();
	void AddCertificate(const u8* cert_data);
	void AddCertificate(const EsCert& cert);

	// deserialise chain
	void DeserialiseCertChain(const u8* data, size_t size);
	bool ValidateChain(const Crypto::sRsa4096Key& root_key) const;
	bool ValidateChainExceptCa() const;
	const std::vector<EsCert>& GetCertificates() const;
	size_t GetCertificateNum() const;

private:
	const std::string kModuleName = "ES_CERT_CHAIN";
	const std::string kCaCertIssuer = "Root";

	ByteBuffer serialised_data_;
	std::vector<EsCert> certs_;
};
