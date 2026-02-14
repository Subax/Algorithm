1. git add: 파일 중 git으로 버전 관리할 파일들을 골라줌 (=staging)
    -> git add .: 모든 파일 선정
    -> add 후에는 stage area로 넘어감

2. git commit -m 'message': staging area에서 repository로 (파일 저장 명령) 

3. git status: 어떤 파일들이 staging되어 있는지?    
    =어떤 파일들이 add되어 있는지
    =어떤 파일들이 staging되어 있는지

4. git log --all --oneline: 커밋 메세지들을 쭉 볼 수 있음

5. git diff: 최근 commit vs 현재파일 차이점 VIM으로 보여줌 but 잘 안씀
    //VIM -> VSCODE editer 변경코드
    git config --global diff.tool vscode
    git config --global difftool.vscode.cmd 'code --wait --diff $LOCAL $REMOTE'

    - git difftool -> 더 보기 쉽게 커밋 데이터와 비교해줌
    - git difftool commitID: 현재파일 vs 특정커밋(노란색 7자리가 커밋 ID) 비교 가능
        ex) git difftool ea46f1b

    => 그냥 vscode 확장프로그램으로 보는 게 편함



branch: 새로운 commit 경로

1. git branch [branch 이름]: 새로운 branch 생성
    -> git switch [branch 이름]: branch 변경 (원래는 main 브랜치)

2. git merge: 두 브랜치를 합침
    ->유지할 branch(ex. main)로 switch
    -> git merge [합칠 브랜치 이름]
        -> 서로 다른 파일을 합침: 잘 됨!
        -> 서로 같은 파일의 같은 줄을 수정 -> 충돌
            -> 직접 수정해야함
            ->
//************************GitFlow
