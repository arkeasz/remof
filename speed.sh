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

clear

hyperfine -N --warmup=10 './remof proone' 'rm -rf protwo'
