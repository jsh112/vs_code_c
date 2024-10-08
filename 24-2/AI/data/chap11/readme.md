# 11장. LSTM 순환 신경망 : 도시 소음 분류 신경망
11장에서는 예제 실습을 위해 캐글의 도시소음 분류 데이터셋 파일들을 이용합니다.<br/>
도시소음 분류 데이터셋 파일들은 캐글 사이트에서 직접 다운로드 받아야 합니다.<br/>

## 캐글 사이트에서 도시소음 분류 데이터셋 다운받기
깃허브 용량 관계상 도시소음 분류 데이터셋은 여기 수록하지 못하며 따라서 사용자별로 각자 다운로드받아야 합니다.<br/><br/>
도시소음 분류 데이터셋 접근 경로는 https://www.kaggle.com/pavansanagapati/urban-sound-classification 입니다.<br/>
데이터 다운로드를 위해서는 먼저 캐글 사이트에 회원가입과 로그인(Sign in)을 해야 합니다.<br/>
캐글에 로그인된 상태에서 위의 경로에 접근해 'Download (6GB)' 버튼을 클릭하면 urban-sound-classification.zip 압축파일을 다운로드받을 수 있고
압축을 풀면 세 개의 압축 파일과 두 개의 csv 파일이 만들어집니다.
<br/>이 가운데 실험에 필요한 파일은 Train.zip 파일 뿐입니다.
Train.zip 파일의 압축을 다시 풀면 Train.csv 파일과 Train 폴더가 만들어지며 Train 폴더 안에 다양한 도시소음 파일들이 만들어집니다.
도시소음 레이블링 정보는 Train.csv 파일 안에 있기 때문에 Train 폴더는 서브폴더 없이 모든 음원 파일을 직접 갖게 됩니다.<br/>
실험을 위해서는 Train.csv 파일과 Train 폴더가 /data/chap11/urban-sound 폴더 밑에 위치하도록 압축 파일 해제 위치를 지정해야 합니다.<br/>
참고로 Test.zip 파일 내용은 음원만 있을 뿐 레이블링 정보가 없기 때문에 실험에 사용하지 않습니다.

## 캐시 파일 생성에 대하여

반복되는 실험에서 음원 데이터의 주파수 스펙트럼 분석 부담을 줄이기 위해 예제 프로그램에서는 캐시를 생성합니다.
캐시는 외부에서 공급되지 않으며 예제 프로그램을 처음 실행시킬 때 자동생성될 것입니다.
참고로 예제 프로그램에서 만들어내는 캐시 파일의 크기는 Train.10-10.cache 파일이 819MB, Train.10-100.cache 파일이 800MB 정도입니다.
이들 캐시 파일은 데이터가 저장된 /data/chap11/urban-sound 폴더에 함께 만들어집니다.

## 11장에서 이용하는 데이터 파일
/data/chap11/urban-sound/Train.csv : 총 1 파일, 94KB<br/>
/data/chap11/urban-sound/Train/\*.wav : 총 5345 파일, 4.0GB<br/>
