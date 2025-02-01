mkdir proone
cd proone
npm init -y
npm install typo
cd ..

mkdir protwo
cd protwo
npm init -y
npm install typo
cd ..

hyperfine './dist/remof project' 'rm -rf project2'
