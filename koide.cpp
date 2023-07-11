//1問目　（日本梨）
if (Question[i].num == 0)
{
	//問題文
	Question[i].sentence[0] = "千葉県が栽培する日本梨で、";
	Question[i].sentence[1] = "おおよその収穫時期が";
	Question[i].sentence[2] = "７月下旬から８月中旬までの";
	Question[i].sentence[3] = "品種は次のうちどれ？";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：幸水";
	Question[i].choices[1] = "B：豊水";
	Question[i].choices[2] = "C：メロン";
	Question[i].choices[3] = "D：秋満月";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'A';

	//問題の解説
	Question[i].tips[0] = "千葉県の日本梨は、";
	Question[i].tips[1] = "産出額、栽培面積、収穫量が１位です。";
}

//2問目　（證誠寺）
if (Question[i].num == 1)
{
	//問題文
	Question[i].sentence[0] = "木更津市の證誠寺に伝わる伝説は、";
	Question[i].sentence[1] = "「日本三大■伝説」のひとつとして有名。";
	Question[i].sentence[2] = "■に入る動物は、次のうちどれ？";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：狐";
	Question[i].choices[1] = "B：蛇";
	Question[i].choices[2] = "C：狸";
	Question[i].choices[3] = "D：人間";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'C';

	//問題の解説
	Question[i].tips[0] = "證誠寺の「狸囃子伝説」を元とした";
	Question[i].tips[1] = "「證誠寺の狸囃子」という童謡があります。";
}
