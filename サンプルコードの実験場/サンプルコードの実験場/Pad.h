// �R���g���[���[
#pragma once

// �R���g���[���[����̓��͏�Ԃ��擾����
namespace Pad
{
	void Update();					// �p�b�h�̓��͏�Ԏ擾
	bool IsPress(int button);		// ������������(�{�^���������Ă���ԁA�����Ɣ���)
	bool IsTrigger(int button);		// �g���K�[����(�{�^�����������u�Ԃ�������)
	bool IsRelase(int button);		// ����������(�{�^���𗣂����u�Ԃ�������)
}