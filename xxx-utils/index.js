#!/usr/bin/env node
// 使用node开发命令工具所执行的javascript脚本

// npm link 执行此命令将bin中的命令链接到全局 mac权限问题加sudo

const program = require('commander')
const package = require('./package.json')

const { createCommanders } = require('./lib/core/commanders')

// version
program.version(package.version, '-v, --version')

// helpoptions
program.option('-c, --copydir', 'copy dir')

// create commande
createCommanders()

program.parse(process.argv)

if (program.args.length < 1) {
  program.help();
}