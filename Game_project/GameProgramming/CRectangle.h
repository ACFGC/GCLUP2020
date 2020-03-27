#ifndef CRECTANGLE_H
/*
#ifndef CRECTANGLE_H
����CRECTANGLE_H��define���Ȃ����#endif�܂ŗL��
*/
#define CRECTANGLE_H //CRECTANGLE_H���`����

//#include "glut.h"
#include "CTexture.h"
#include"CTaskManager.h"

/*
CRectangle�N���X
�l�p�`�Ɋւ���N���X
*/
class CRectangle :public CTask {
public:
	//�񋓌^�̒�`
	enum ETag {
		EBLOCK,	//�u���b�N
		EPLAYER,//�v���C���[
		EATTACK,//�U����
		ENHANCEDATTACK,//�����U��
		EBURN,//�G�̉΂̋�
		EDEATHBLOW,//�K�E�Z
		EBOSSDEATHBLOW,//�{�X�K�E�Z
		ESLIMEENEMY,//�X���C���^�̎G���G
		EMISTRESS,//�X�̃{�X
		ECATENEMY,//�L�^�̎G���G
		ERABBITBOSS,//�e�^�̃{�X
		EDUMMYENEMY,//�_�~�[�̎G���G
		EDUMMYPLAYER,//�_�~�[�̎G���v���C���[�ɕϐg���
		ELASTMYF,//���X�{�X
		EENEMY,  //�G�̊�{����
		EMISTRESSES,//�X�{�X����
	};
	ETag mTag;	//�񋓌^�̕ϐ�
	//�f�t�H���g�R���X�g���N�^
	CRectangle(int priority);
	CRectangle();
	~CRectangle();

	//bool mEnabled;	// true : Update Collision Render

	enum EStatus {
		EENABLED,	//
		EDISABLED,	// mEnabled true -> false
		EDELETE,	// delete list
	};
	EStatus mStatus;

	float x;		//���S��X���W
	float y, w, h, z, d;	//���S��Y���W,��,����,���s��



	/*
	DrawTriangle
	�O�p�`��`�悷��֐�
	*/
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
	/*
	DrawRectangle
	�l�p�`��`�悷��֐�
	x0,y0:�E��
	x1,y1:����
	x2,y2:����
	x3,y3:�E��
	*/
	void DrawRectangle(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);

	/*
	Draw
	�@�l�p�`��`�悷��֐�
	 */
	virtual void Render();
	/*
	Collision
	�l�p�`r�ƏՓ˂��Ă����true��
	���Ă��Ȃ����false��Ԃ��܂��B
	*/
    bool Collision(const CRectangle &r);
	/*
	Collision
	����*pr�̎l�p�`�ƏՓ˂��Ă��邩���o���A
	�Փ˂��Ă����true���A���Ă��Ȃ����false��Ԃ��B
	�܂��A�Փ˂��Ă����ꍇ�A*px��X�������ɏd�Ȃ����ʂ��A
	*py��Y�������֏d�Ȃ����ʂ�ݒ肷��B
	*/
	bool Collision(CRectangle *pr, int *px, int *py);
	/*
	�e�N�X�`���̕`��
	t:�e�N�X�`���̃|�C���^ left:�e�N�X�`���̍�X���W right:�e�N�X�`���̉EX���W
	bottom:�e�N�X�`���̉�Y���W top:�e�N�X�`���̏�Y���W
	*/
	virtual void Render(CTexture &t, int left, int right
		, int bottom, int top) {
		t.DrawImage(x - w, x + w, y - h, y + h
			, left, right, bottom, top);
	}

	virtual void Update() {};

	//36
	
};

#include <vector>
//�ϒ��z��̒�`
extern std::vector<CRectangle*> VectorRect;

#endif //#ifndef�̏I���