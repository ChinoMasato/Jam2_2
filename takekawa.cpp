//6��ځi�卪�j
if (Question[i].num == 5)
{
	//��蕶
	Question[i].sentence[0] = "���̂����A��t���ł̐��Y�ʂ�";
	Question[i].sentence[1] = "���{��ł����؁E�_�앨�͂ǂ�H";

	Question[i].Image_Graphic = LoadGraph("");//���̃C���[�W�摜��ϐ��ɓǂݍ���

	//�I����
	Question[i].choices[0] = "A�F��������";
	Question[i].choices[1] = "B�F�Ԃ��";
	Question[i].choices[2] = "C�F������";
	Question[i].choices[3] = "D�F�卪";

	//�����iA�AB�AC�AD�̂ǂꂩ����́j
	Question[i].answer = 'D';

	//���̉��
	Question[i].tips[0] = "�����Y�̗��Ԑ���8���́A";
	Question[i].tips[1] = "��t���Ő��Y����Ă��܂��B";
}
//7��ځi���p���j
if (Question[i].num == 6)
{
	//��蕶
	Question[i].sentence[0] = "��t���̈�׏��t�߂ɓ`�����Ă���";
	Question[i].sentence[1] = "���`���ł́A���̑̂��R�ɗ􂯂�";
	Question[i].sentence[2] = "���ꂼ�ꂪ�������ꏊ�ɁA";
	Question[i].sentence[3] = "�������A���������ł����B";
	Question[i].sentence[4] = "���ƈ�́H";

	Question[i].Image_Graphic = LoadGraph("");//���̃C���[�W�摜��ϐ��ɓǂݍ���

	//�I����
	Question[i].choices[0] = "A�F������";
	Question[i].choices[1] = "B�F������";
	Question[i].choices[2] = "C�F���p��";
	Question[i].choices[3] = "D�F���厛";

	//�����iA�AB�AC�AD�̂ǂꂩ����́j
	Question[i].answer = 'C';

	//���̉��
	Question[i].tips[0] = "���p���͐�t����׌S�h����";
	Question[i].tips[1] = "����A�V���I�ȏ�O�ɑn��";
	Question[i].tips[2] = "���ꂽ�A�֓����w�̌Î��ł��B";
}
//8��ځi���Ԑ��j
if (Question[i].num == 7)
{
	//��蕶
	Question[i].sentence[0] = "���̂����A��t���ł̐��Y�ʂ�";
	Question[i].sentence[1] = "���{��ł����؁E�_�앨�͂ǂ�H";

	Question[i].Image_Graphic = LoadGraph("");//���̃C���[�W�摜��ϐ��ɓǂݍ���

	//�I����
	Question[i].choices[0] = "A�FApple��";
	Question[i].choices[1] = "B�F���Ԑ�";
	Question[i].choices[2] = "C�F�ӂȂ����[";
	Question[i].choices[3] = "D�F������";

	//�����iA�AB�AC�AD�̂ǂꂩ����́j
	Question[i].answer = 'B';

	//���̉��
	Question[i].tips[0] = "�����Y�̗��Ԑ���8���́A";
	Question[i].tips[1] = "��t���Ő��Y����Ă��܂��B";
}