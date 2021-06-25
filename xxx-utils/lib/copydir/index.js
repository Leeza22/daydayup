const fs = require('fs')
const fsp = require('fs/promises')
const path = require('path')

const chalk = require('chalk')

const copyConfig = require('../copydir/config')
// https://www.cnblogs.com/coding4/p/7495968.html


// 获取系统下绝对路径
// const resolvePath = (partPath) => {
//   // console.log(path.resolve(partPath))
//   // // return path.resolve(partPath)
// }

const isDir = async (src) => {
  try {
    const stat = await fsp.stat(src);
    if (stat.isDirectory()) return stat
    else return false
  } catch(error) {
    return false
    // console.log(chalk.red("no such file or directory: " + src))
  }
}

const existDir = async (dir) => {
  try {
    await fsp.mkdir(dir, { recursive: true });
    console.log(chalk.green('create: ' + dir))
  } catch(error) {
    console.log(chalk.red('文件夹创建失败'));
  }
}

const rmFile = async (dir) => {
  try {
    await fsp.unlink(dir);
    console.log(chalk.keyword('orange')('remove：' + dir));
  } catch(error) {
    console.log(chalk.red('error in file remove：' + dir));
  }
}

const readDir = async (dir) => {
  try {
    const files = await fsp.readdir(dir, 'utf-8');
    if (files) return files;
    else console.log(chalk.red('error in read file：' + dir));
  } catch(error) {
    console.log(chalk.red('error in read file：' + dir));
  }
}

// 删除空文件夹
const rmDir = async (dir) => {
  try {
    await fsp.rmdir(dir);
    console.log(chalk.keyword('orange')('remove：' + dir));
  } catch(error) {
    console.log(chalk.red('error in dir remove：' + dir));
  }
}

// 删除文件夹下内容
const rmDirContent = async (dir) => {
  const fileList = await readDir(dir);
  if (fileList.length > 0) {
    for (let child of fileList) {
      const child_path = dir + '/' + child;
      const isDirectory = await isDir(child_path);
      if (isDirectory) {
        await rmDirContent(child_path)
      } else {
        await rmFile(child_path)
      }
    }
  }
  await rmDir(dir)
}

const remove = async (dir) => {
  const stat = await isDir(dir)
  if (stat) {
    await rmDirContent(dir)
  } else {
    await rmFile(dir)
  }
}

const copyDirContent = async (from, to) => {
  await existDir(to) // 创建
  const fileList = await readDir(from);
  // forEach 不能保证async 回调函数的调用
  for (let child of fileList) {
    const child_from = from + '/' + child;
    const child_to = to + '/' + child;
    const isDirectory = await isDir(child_from)
    if (isDirectory) {
      await copyDirContent(child_from, child_to)
    } else {
      await copyFile(child_from, child_to)
    }
  }
}

const copyFile = async (from, to) => {
  try {
    await fsp.copyFile(from, to);
    console.log(chalk.hex('#d1c7b7')('\nfrom: ' + from))
    console.log(chalk.green('to -> ' + to))
  } catch(error) {
    console.log(chalk.red('error in file copy：' + from));
  }
}


const copy = async (from, to) => {
  // 获取参数 //校验文件夹
  const isDirectory1 = await isDir(from)
  if (!isDirectory1) {
    if (copyConfig[from]) {
      // const config = copyConfig[from] // from 先改变的话 to就找不到
      to = copyConfig[from].to
      from = copyConfig[from].from
      const isDirectory = await isDir(from)
      if (!isDirectory) {
        console.log(chalk.red('文件夹错误'))
        // console.log(chalk.red('文件夹错误,请重新输入...'))
        return
      }
    } else {
      console.log(chalk.red('文件夹错误'))
      return
    }
  }

  // 校验/生成to/重生to/ 旧的to 先copy
  if (fs.existsSync(to)) {
    console.log(chalk.blue('移除已存在文件...'));
    await remove(to);
    console.log(chalk.blue('移除完毕'));
  }

  // copy复制
  console.log(chalk.blue('开始拷贝...'));
  await copyDirContent(from, to);
  console.log(chalk.blue.bold('\n\n拷贝成功！'));
}

module.exports = copy
