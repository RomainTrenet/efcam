'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var compass = require('gulp-compass');
var sourcemaps = require('gulp-sourcemaps');
var autoprefixer = require('gulp-autoprefixer');

gulp.task('sass:prod', function () {
  gulp.src('./sass/*.scss')
    .pipe(sass().on('error', sass.logError))
    .pipe(autoprefixer({
       browsers: ['last 2 version']
    }))
    .pipe(gulp.dest('./css'));
});

gulp.task('sass:dev', function () {
  //gulp.src('./sass/*.scss')
  gulp.src('./sass/**/*.scss')
    .pipe(sourcemaps.init())
    //.pipe(compass())
      .pipe(compass({
          css: 'css',
          sass: 'sass',
          image: 'images'
      }))
      /*.pipe(compass({
          css: 'app/assets/css',
          sass: 'app/assets/sass',
          image: 'app/assets/images'
      }))*/
    //.pipe(sass().on('error', sass.logError))
    .pipe(sass({ compass: true, sourcemap: true, style: 'expanded' }).on('error', sass.logError))//compressed
    .pipe(autoprefixer({
      browsers: ['last 2 version']
    }))
    .pipe(sourcemaps.write('.'))
    .pipe(gulp.dest('./css'));
});

gulp.task('sass:watch', function () {
  gulp.watch('./sass/**/*.scss', ['sass:dev']);
});

gulp.task('default', ['sass:dev', 'sass:watch']);
