#ifndef IDV_D3DTEXTURE
#define IDV_D3DTEXTURE

#include <IDVVideo\IDVBaseDriver.h>


#include <d3d11.h>
#include <wrl.h>
#include <wrl/client.h>
using namespace Microsoft::WRL;


class D3DXTexture : public Texture {
public:
	D3DXTexture() {}

	void	SetTextureParams();
	void	GetFormatBpp(unsigned int &props, unsigned int &Format, unsigned int &bpp);

	void	LoadAPITexture(unsigned char* buffer);
	void	LoadAPITextureCompressed(unsigned char* buffer);
	void	DestroyAPITexture();

	ComPtr<ID3D11Texture2D>				Tex;
	ComPtr<ID3D11ShaderResourceView>    pSRVTex;
	ComPtr<ID3D11SamplerState>          pSampler;

};

#endif