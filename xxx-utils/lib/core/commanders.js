const program = require('commander')
const { copyDirAction } = require('./actions')

const createCommanders = () => {
  program.command('copydir <from> <to>')
          .description('拷贝文件夹从一个目录到另一个指定目录')
          .action((from, to) => copyDirAction(from, to))
}
module.exports = {
  createCommanders
}